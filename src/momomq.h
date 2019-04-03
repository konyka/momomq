/**
 *===========================================================================
 *  DarkBlue Engine Source File.
 *  Copyright (C), DarkBlue Studios.
 * -------------------------------------------------------------------------
 *    File name: momomq.h
 *      Version: v0.0.0
 *   Created on: Apr 3, 2019 by konyka
 *       Editor: Sublime Text3
 *  Description: 
 * -------------------------------------------------------------------------
 *      History:
 *
 *===========================================================================
 */
 

#ifndef __DARKBLUE_MOMOMQ_H__
#define __DARKBLUE_MOMOMQ_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <stddef.h>
#include <stdint.h>

 /*
  *Socket .定义
  */                                                       


struct mm_iovec {
    size_t iov_len;
    void *iov_base;
};




#ifdef __cplusplus
}
#endif  

#endif /* __DARKBLUE_MOMOMQ_H__ */
