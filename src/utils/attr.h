/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: attr.h
 *      Version: v0.0.0
 *   Created on: Apr 5, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_ATTR_H__
#define __DARKBLUE_MM_ATTR_H__

#if defined __GNUC__ || defined __llvm__
#define MM_UNUSED __attribute__ ((unused))
#else
#define MM_UNUSED
#endif

#endif /* __DARKBLUE_MM_ATTR_H__ */
