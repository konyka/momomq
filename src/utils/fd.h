/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: fd.h
 *      Version: v0.0.0
 *   Created on: Apr 7, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_FD_H__
#define __DARKBLUE_MM_FD_H__

#ifdef MM_HAVE_WINDOWS
#include "win.h"
typedef SOCKET mm_fd;
#else
typedef int mm_fd;
#endif

#endif /* __DARKBLUE_MM_FD_H__ */
