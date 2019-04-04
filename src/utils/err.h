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

/*  包含 mm.h 头文件，其中定义了特定的错误码*/
#include "../mm.h"

#include "likely.h"

//这个属性告诉编译器函数不会返回，这可以用来禁用有关未达到代码路径的错误.
//this can be used to suppress errors about code paths not being reached.
#if defined _MSC_VER
#define MM_NO_RETURN __declspec(noreturn)
#elif defined __GNUC__
#define MM_NO_RETURN __attribute__ ((noreturn))
#else
#define MM_NO_RETURN
#endif

/**
 *
*/

/**
 *与系统assert（）相同。 但是，在Win32环境下 断言assert有一些不足之处。
     因此我们使用这个宏。
*/

#define mm_assert(x) \
    do {\
        if (mm_unlikely (!(x))) {\
            mm_backtrace_print (); \
            fprintf (stderr, "Assertion failed: %s (%s:%d)\n", #x, \
                __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)



#define mm_assert_state(obj, state_name) \
    do {\
        if (mm_unlikely ((obj)->state != state_name)) {\
            mm_backtrace_print (); \
            fprintf (stderr, \
                "Assertion failed: %d == %s (%s:%d)\n", \
                (obj)->state, #state_name, \
                __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)

/*  Checks whether memory allocation was successful. */
#define alloc_assert(x) \
    do {\
        if (mm_unlikely (!x)) {\
            mm_backtrace_print (); \
            fprintf (stderr, "Out of memory (%s:%d)\n",\
                __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)

/*  Check the condition. If false prints out the errno. */
#define errno_assert(x) \
    do {\
        if (mm_unlikely (!(x))) {\
            mm_backtrace_print (); \
            fprintf (stderr, "%s [%d] (%s:%d)\n", mm_err_strerror (errno),\
                (int) errno, __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)

/*  Checks whether supplied errno number is an error. */
#define errnum_assert(cond, err) \
    do {\
        if (mm_unlikely (!(cond))) {\
            mm_backtrace_print (); \
            fprintf (stderr, "%s [%d] (%s:%d)\n", mm_err_strerror (err),\
                (int) (err), __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)

/* Checks the condition. If false prints out the GetLastError info. */
#define win_assert(x) \
    do {\
        if (mm_unlikely (!(x))) {\
            char errstr [256];\
            DWORD errnum = WSAGetLastError ();\
            mm_backtrace_print (); \
            mm_win_error ((int) errnum, errstr, 256);\
            fprintf (stderr, "%s [%d] (%s:%d)\n",\
                errstr, (int) errnum, __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)

/* Checks the condition. If false prints out the WSAGetLastError info. */
#define wsa_assert(x) \
    do {\
        if (mm_unlikely (!(x))) {\
            char errstr [256];\
            DWORD errnum = WSAGetLastError ();\
            mm_backtrace_print (); \
            mm_win_error (errnum, errstr, 256);\
            fprintf (stderr, "%s [%d] (%s:%d)\n",\
                errstr, (int) errnum, __FILE__, __LINE__);\
            fflush (stderr);\
            mm_err_abort ();\
        }\
    } while (0)

/*  Assertion-like macros for easier fsm debugging. */
#define mm_fsm_error(message, state, src, type) \
    do {\
        mm_backtrace_print(); \
        fprintf (stderr, "%s: state=%d source=%d action=%d (%s:%d)\n", \
            message, state, src, type, __FILE__, __LINE__);\
        fflush (stderr);\
        mm_err_abort ();\
    } while (0)

#define mm_fsm_bad_action(state, src, type) mm_fsm_error(\
    "Unexpected action", state, src, type)
#define mm_fsm_bad_state(state, src, type) mm_fsm_error(\
    "Unexpected state", state, src, type)
#define mm_fsm_bad_source(state, src, type) mm_fsm_error(\
    "Unexpected source", state, src, type)

/*  编译时assert. */
#define CT_ASSERT_HELPER2(prefix, line) prefix##line
#define CT_ASSERT_HELPER1(prefix, line) CT_ASSERT_HELPER2(prefix, line)
#if defined __COUNTER__
#define CT_ASSERT(x) \
    typedef int CT_ASSERT_HELPER1(ct_assert_,__COUNTER__) [(x) ? 1 : -1]
#else
#define CT_ASSERT(x) \
    typedef int CT_ASSERT_HELPER1(ct_assert_,__LINE__) [(x) ? 1 : -1]
#endif

MM_NORETURN void mm_err_abort (void);
int mm_err_errno (void);
const char *mm_err_strerror (int errnum);
void mm_backtrace_print (void);

#ifdef MM_HAVE_WINDOWS
int mm_err_wsa_to_posix (int wsaerr);
void mm_win_error (int err, char *buf, size_t bufsize);
#endif



#endif /* __DARKBLUE_MM_ERR_H__ */
