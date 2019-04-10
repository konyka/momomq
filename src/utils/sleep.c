/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: sleep.c
 *      Version: v0.0.0
 *   Created on: Apr 8, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#include "sleep.h"
#include "err.h"

#ifdef MM_HAVE_WINDOWS

#include "win.h"

void mm_sleep (int milliseconds)
{
    Sleep (milliseconds);
}

#else

#include <time.h>

void mm_sleep (int milliseconds)
{
    int rc;
    struct timespec ts;

    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = milliseconds % 1000 * 1000000;
    rc = momosleep (&ts, NULL);
    errno_assert (rc == 0);    
}

#endif

