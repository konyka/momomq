/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: thread.h
 *      Version: v0.0.0
 *   Created on: Apr 10, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_THREAD_H__
#define __DARKBLUE_MM_THREAD_H__

/*  不依赖平台的线程实现。 */

typedef void (mm_thread_routine) (void*);

#if defined MM_HAVE_WINDOWS
#include "thread_win.h"
#else
#include "thread_posix.h"
#endif

void mm_thread_init (struct mm_thread *self,
    mm_thread_routine *routine, void *arg);
void mm_thread_term (struct mm_thread *self);

#endif /* __DARKBLUE_MM_THREAD_H__ */
