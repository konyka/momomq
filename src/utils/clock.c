/**
 *===========================================================================
 *  None Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: clock.c
 *      Version: v0.0.0
 *   Created on: 2019-05-11 23:12:49 by konyka
 *  Modified by: konyka
 *Modified time: 2019-05-12 22:53:59
 *       Editor: Sublime Text3
 *        Email: 
 *  Description: 
 * -------------------------------------------------------------------------
 *      History: 
 *
 *===========================================================================
 */
 
#if defined MM_HAVE_WINDOWS
#include "win.h"
#elif defined MM_HAVE_OSX
#include <mach/mach_time.h>
#elif defined MM_HAVE_CLOCK_MONOTONIC || defined MM_HAVE_GETHRTIME
#include <time.h>
#else
#include <sys/time.h>
#endif

#include "clock.h"
#include "likely.h"
#include "err.h"
#include "attr.h"

uint64_t mm_clock_ms (void)
{
#if defined MM_HAVE_WINDOWS

    LARGE_INTEGER tps;
    LARGE_INTEGER time;
    double tpms;

    QueryPerformanceFrequency (&tps);
    QueryPerformanceCounter (&time);
    tpms = (double) (tps.QuadPart / 1000);
    return (uint64_t) (time.QuadPart / tpms);

#elif defined MM_HAVE_OSX

    static mach_timebase_info_data_t mm_clock_timebase_info;
    uint64_t ticks;

    /**
     * 如果全局的timebase info没有初始化，就对其进行初始化。
     */
    if (mm_unlikely (!mm_clock_timebase_info.denom))
        mach_timebase_info (&mm_clock_timebase_info);

    ticks = mach_absolute_time ();
    return ticks * mm_clock_timebase_info.numer /
        mm_clock_timebase_info.denom / 1000000;

#elif defined MM_HAVE_GETHRTIME

    return gethrtime () / 1000000;

#elif defined MM_HAVE_CLOCK_MONOTONIC

    int rc;
    struct timespec tv;

    rc = clock_gettime (CLOCK_MONOTONIC, &tv);
    errno_assert (rc == 0);
    return tv.tv_sec * (uint64_t) 1000 + tv.tv_nsec / 1000000;

#else

    int rc;
    struct timeval tv;

    /**
     * Gettimeofday在一些系统上运行的比较慢， 因此，用作最后的手段。
     */
    rc = gettimeofday (&tv, NULL);
    errno_assert (rc == 0);
    return tv.tv_sec * (uint64_t) 1000 + tv.tv_usec / 1000;

#endif
}







