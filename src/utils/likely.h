/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: likely.h
 *      Version: v0.0.0
 *   Created on: Apr 4, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_FAST_H__
#define __DARKBLUE_MM_FAST_H__

#if defined __GNUC__ || defined __llvm__
#define mm_likely(x) __builtin_expect (!!(x), 1)
#define mm_unlikely(x) __builtin_expect (!!(x), 0)
#else
#define mm_likely(x) (x)
#define mm_unlikely(x) (x)
#endif

#endif

#endif /* __DARKBLUE_MM_FAST_H__ */
