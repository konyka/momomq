/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: reqresp_demo.c
 *      Version: v0.0.0
 *   Created on: Apr 3, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
/* 
MAX_JOBS_NUMBER是队列化的、向外提供请求的数量限制。 如果超过这个限制，就不接受进来的请求。
其原因是为了防止恶意客户端不断创建新的作业请求，从而消耗完所有的服务器资源。
*/

#define MAX_JOBS_NUMBER 100
/*
服务器维护一个工作列表，根据到期时间进行排序，这样就可以在泗洪poll的时候，通过这个list
将超时设置为适当的值。
*/
struct work {
    struct work *next;
    uint64_t expiration_time;
    void *control;
};

/*
返回时间，单位为毫秒。由于使用了平台相关的gettimeofday，因此只能在类unix系统上运行。
*/

uint64_t milliseconds (void)
{
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (((uint64_t)tv.tv_sec * 1000) + ((uint64_t)tv.tv_usec / 1000));
}

void usege(int argc, char *argv[]) {
    fprintf (stderr, "usage: %s <mm url> [-s | name ]\n", argv[0]);
}

int server(const char *url)
{
    int fd; 
    struct work *worklist = NULL;
    int npending = 0;

    /*  创建scoket. */
    fd = mm_socket(AF_SP_RAW, MM_REP);
    if (fd < 0) {
        fprintf (stderr, "mm_socket: %s\n", mm_strerror (mm_errno ()));
        return (-1);
    }

    /*  绑定 URL.  这会以同步的方式绑定、监听；新来的客户端会以异步的方式被accept。
    除此之外，调用端不会有其他的动作。
     */

    if (mm_bind (fd, url) < 0) {
        fprintf (stderr, "mm_bind: %s\n", mm_strerror (mm_errno ()));
        mm_close (fd);
        return (-1);
    }

    /* 主循环. */

    while (1) {
        uint32_t timer;
        int rc;
        int timeout;
        uint64_t now;
        struct work *work, **srch;
        uint8_t *body;
        void *control;
        struct mm_iovec iov;
        struct mm_msghdr hdr;
        struct mm_pollfd pfd[1];

        /* 
        检查是否有工作请求已经处理完，以及是否可以对其进行相应
        */

        timeout = -1;
        while ((work = worklist) != NULL) {

            now = milliseconds ();
            if (work->expiration_time> now) {
                timeout = (work->expiration_time- now);
                break;
            }
            worklist = work->next;
            npending--;
            rc = mm_sendmsg (fd, &work->request, MM_DONTWAIT);
            if (rc < 0) {
                fprintf (stderr, "mm_sendmsg: %s\n",
                    mm_strerror (mm_errno ()));
                mm_freemsg (work->request.msg_control);
            }
            free (work);
        }

        /*  
        确保队列化的并发任务不会超出我们允许的限制设置。
        这可以保护服务端免受恶意或非正常客户端耗尽系统的资源。 
        */

        if (npending >= MAX_JOBS_NUMBER) {
            mm_poll (pfd, 0, timeout);
            continue;
        }

        pfd[0].fd = fd;
        pfd[0].events = MM_POLLIN;
        pfd[0].revents = 0;
        mm_poll (pfd, 1, timeout);

        if ((pfd[0].revents & MM_POLLIN) == 0) {
            continue;
        }

        /* 
        接收消息 处理消息（解析消息 为其创建工作请求，并将其添加到工作列表中）
         */

        memset (&hdr, 0, sizeof (hdr));
        control = NULL;
        iov.iov_base = &body;
        iov.iov_len = MM_MSG;
        hdr.msg_iov = &iov;
        hdr.msg_iovlen = 1;
        hdr.msg_control = &control;
        hdr.msg_controllen = MM_MSG;

        rc = mm_recvmsg (fd, &hdr, 0);
        if (rc < 0) {
            /*  出现了错误. */
            fprintf (stderr, "mm_recv: %s\n", mm_strerror (mm_errno ()));
            break;
        }
        if (rc != sizeof (uint32_t)) {
            fprintf (stderr, "mm_recv: wanted %d, but got %d\n",
                (int) sizeof (uint32_t), rc);
            mm_freemsg (body);
            mm_freemsg (control);
            continue;
        }

        memcpy (&timer, body, sizeof (timer));
        mm_freemsg (body);

        work = malloc (sizeof (*work));
        if (work == NULL) {
            fprintf (stderr, "malloc: %s\n", strerror (errno));
            /*  出现错误 -- 当然也可以加入其他的错误处理流程 */
            break;
        }
        memset (work, 0, sizeof (*work));
        work->expiration_time = milliseconds () + ntohl (timer);
        work->control = control;
        work->request.msg_iovlen = 0;  /*  无需发送负载数据 payload data. */
        work->request.msg_iov = NULL;
        work->request.msg_control = &work->control;
        work->request.msg_controllen = MM_MSG;

        /*  把工作请求插入到列表 */
        srch = &worklist;
        for (;;) {
            if ((*srch == NULL) || ((*srch)->expiration_time> work->expiration_time)) {
                work->next = *srch;
                *srch = work;
                npending++;
                break;
            }
            srch = &((*srch)->next);
        }
    }

    /*  
    结束队列中的孤儿请求。无论如何，反正只要有错误就exit ，释放资源，所以没什么好担心的
     */

    mm_close (fd);
    return (-1);
}


int main (int argc, char *argv[]) {

    if (argc < 3) {
        usege(argc, argv);
        exit (EXIT_FAILURE);
    }

        if (strcmp (argv[2], "-s") == 0) {
        rc = server (argv[1]);
    } else {
        //rc = client (argv[1], argv[2]);
    }
    exit (rc == 0 ? EXIT_SUCCESS : EXIT_FAILURE);

}



