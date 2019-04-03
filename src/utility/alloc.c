/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: alloc.c
 *      Version: v0.0.0
 *   Created on: Apr 3, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 
#include "alloc.h"

#if defined mm_ALLOC_MONITOR

// to do

#else


#include <stdlib.h>

void mm_alloc_init (void)
{
}

void mm_alloc_term (void)
{
}

void *mm_alloc_ (size_t size)
{
    return malloc (size);
}

void *mm_realloc (void *ptr, size_t size)
{
    return realloc (ptr, size);
}

void mm_free (void *ptr)
{
    free (ptr);
}

//to do

#endif











