/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: mutex.h
 *      Version: v0.0.0
 *   Created on: Apr 3, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_MUTEX_H__
#define __DARKBLUE_MM_MUTEX_H__



#ifdef MM_HAVE_WINDOWS
#include "win.h"
#else
#include <pthread.h>
#endif


struct mm_mutex {
    /*   私有字段  */
#ifdef MM_HAVE_WINDOWS
    CRITICAL_SECTION cs;
    DWORD owner;
    int debug;
#else
    pthread_mutex_t mutex;
#endif
};


typedef struct mm_mutex mm_mutex_t;

/*  初始化 mutex. */
void mm_mutex_init (mm_mutex_t *self);

/*  销毁 mutex. */
void mm_mutex_term (mm_mutex_t *self);

/*  上锁 mutex. 在相同的线程中多重上锁的行为是未定义的*/
void mm_mutex_lock (mm_mutex_t *self);

/*  解锁mutex. 解锁未上锁的mutex的行为是未定义的*/
void mm_mutex_unlock (mm_mutex_t *self);


#endif /* __DARKBLUE_MM_MUTEX_H__ */
