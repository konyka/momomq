/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: utility.h
 *      Version: v0.0.0
 *   Created on: Apr 3, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_UTILITY_H__
#define __DARKBLUE_UTILITY_H__

这些函数可以拦截与内存分配相关的操作。

void mm_alloc_init (void);
void mm_alloc_term (void);
void *mm_realloc (void *ptr, size_t size);
void mm_free (void *ptr);

#if defined MM_ALLOC_MONITOR
#define mm_alloc(size, name) mm_alloc_ (size, name)
void *mm_alloc_ (size_t size, const char *name);
#else
#define mm_alloc(size, name) mm_alloc_(size)
void *mm_alloc_ (size_t size);
#endif

#endif /* __DARKBLUE_UTILITY_H__ */
