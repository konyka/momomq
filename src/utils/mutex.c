/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: mutex.c
 *      Version: v0.0.0
 *   Created on: Apr 4, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 


 #include "mutex.h"
#include "err.h"

#include <stdlib.h>

#ifdef MM_HAVE_WINDOWS

//to do
void mm_mutex_init (mm_mutex_t *self)
{
    InitializeCriticalSection (&self->cs);
    self->owner = 0;
}

void mm_mutex_term (mm_mutex_t *self)
{
        /*  释放上锁的临界区/互斥量 mutex. */
    mm_assert(self->owner == 0);
    DeleteCriticalSection (&self->cs);
}

void mm_mutex_lock (mm_mutex_t *self)
{
    EnterCriticalSection (&self->cs);

    /*  确保不会递归进入临界区/互斥量mutex. */
    mm_assert(self->owner == 0);
    self->owner = GetCurrentThreadId();
}

void mm_mutex_unlock (mm_mutex_t *self)
{
    /*  确保我们持有的临界区/互斥量 就是我们正在释放的临界区/互斥量mutex  */
    mm_assert(self->owner == GetCurrentThreadId());
    self->owner = 0;
    LeaveCriticalSection (&self->cs);
}


#else

//to do
void mm_mutex_init (mm_mutex_t *self)
{

    int rc;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    rc = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
    errnum_assert (rc == 0, rc);
    rc = pthread_mutex_init (&self->mutex, NULL);
    errnum_assert (rc == 0, rc);
    pthread_mutexattr_destroy(&attr);

}

void mm_mutex_term (mm_mutex_t *self)
{
    int rc;

    rc = pthread_mutex_destroy (&self->mutex);
    errnum_assert (rc == 0, rc);
}

void mm_mutex_lock (mm_mutex_t *self)
{
    int rc;

    rc = pthread_mutex_lock (&self->mutex);
    errnum_assert (rc == 0, rc);
}

void mm_mutex_unlock (mm_mutex_t *self)
{
    int rc;

    rc = pthread_mutex_unlock (&self->mutex);
    errnum_assert (rc == 0, rc);
}



#endif
