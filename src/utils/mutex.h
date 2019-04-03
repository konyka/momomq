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


#endif /* __DARKBLUE_MM_MUTEX_H__ */
