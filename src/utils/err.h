/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: err.h
 *      Version: v0.0.0
 *   Created on: Apr 4, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_ERR_H__
#define __DARKBLUE_MM_ERR_H__


#include <errno.h>
#include <stdio.h>
#include <string.h>

//这个属性告诉编译器函数不会返回，这可以用来禁用有关未达到代码路径的错误.
//this can be used to suppress errors about code paths not being reached.
#if defined _MSC_VER
#define MM_NO_RETURN __declspec(noreturn)
#elif defined __GNUC__
#define MM_NO_RETURN __attribute__ ((noreturn))
#else
#define MM_NO_RETURN
#endif







#endif /* __DARKBLUE_MM_ERR_H__ */
