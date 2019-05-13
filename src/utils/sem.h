/**
 *===========================================================================
 *  None Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: sem.h
 *      Version: v0.0.0
 *   Created on: 2019-04-24 22:51:04 by konyka
 *  Modified by: konyka
 *Modified time: 2019-05-13 19:55:50
 *       Editor: Sublime Text3
 *        Email: 
 *  Description: 
 * -------------------------------------------------------------------------
 *      History: 
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_SEM_H__
#define __DARKBLUE_MM_SEM_H__

/*  简单的信号量。 它只能有两个值（0/1，即锁定/解锁）. */

struct mm_sem;

/*  初始化sem对象。 创建的时候，状态为锁定状态是. */
void mm_sem_init (struct mm_sem *self);

/*  销毁sem对象。 */
void mm_sem_term (struct mm_sem *self);

/*  U解锁信号量semaphore. */
void mm_sem_post (struct mm_sem *self);

/*  等待，一直到信号量对象变成解锁状态，然后对其锁定 */
int mm_sem_wait (struct mm_sem *self);

#if defined MM_HAVE_WINDOWS

#include "win.h"

struct mm_sem {
    HANDLE h;
};

#elif defined MM_HAVE_SEMAPHORE

#include <semaphore.h>

struct mm_sem {
    sem_t sem;
};

#else /*  使用条件变量 condition variable 模拟信号量 semaphore. */

#include <pthread.h>

struct mm_sem {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int signaled;
};

#endif

#endif /* __DARKBLUE_MM_SEM_H__ */
