/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: random.h
 *      Version: v0.0.0
 *   Created on: Apr 7, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_RANDOM_H__
#define __DARKBLUE_MM_RANDOM_H__

#include <stddef.h>

/**
 * [mm_random_seed  种子伪随机数生成器]
 */
void mm_random_seed ();

/*  . */
/**
 * [mm_random_generate  生成伪随机字节序列]
 * @param buf [description]
 * @param len [description]
 */
void mm_random_generate (void *buf, size_t len);

#endif /* __DARKBLUE_MM_RANDOM_H__ */
