/**
 *===========================================================================
 *  None Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: win.h
 *      Version: v0.0.0
 *   Created on: 2019-04-21 22:11:08 by konyka
 *  Modified by: konyka
 *Modified time: 2019-04-21 22:15:46
 *       Editor: Sublime Text3
 *        Email: 
 *  Description: 
 * -------------------------------------------------------------------------
 *      History: 
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MM_WIN_H__
#define __DARKBLUE_MM_WIN_H__

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <mswsock.h>
#include <process.h>
#include <ws2tcpip.h>

/**
 * Windows平台上不存在此结构。 我们自己构造吧。
 */
struct sockaddr_un {
    short sun_family;
    char sun_path [sizeof (struct sockaddr_storage) -
        sizeof (short)];
};

#define ssize_t int

#endif /* __DARKBLUE_MM_WIN_H__ */
