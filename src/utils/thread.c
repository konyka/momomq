/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: thread.c
 *      Version: v0.0.0
 *   Created on: Apr 10, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#include "thread.h"

#ifdef MM_HAVE_WINDOWS
#include "thread_win.inc"
#else
#include "thread_posix.inc"
#endif

