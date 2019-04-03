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

struct mm_msg_header {
    int msg_iovlen;
    struct mm_iovec *msg_iov;
    size_t msg_controllen;  
    void *msg_control;
};


#ifdef __cplusplus
}
#endif  

#endif /* __DARKBLUE_MOMOMQ_H__ */
