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
struct work_list {
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



