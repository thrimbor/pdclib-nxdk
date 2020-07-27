/* Diagnostics <assert.h>

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include "pdclib/_PDCLIB_aux.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _PDCLIB_ASSERT_H
#define _PDCLIB_ASSERT_H
void _xbox_assert(char const * const expression, char const * const file_name, char const * const function_name, unsigned long line);
#endif

/* If NDEBUG is set, assert() is a null operation. */
#undef assert

#ifdef NDEBUG
    #define assert(ignore) ((void)0)
#else
    #define assert(expression) \
        do { \
            if(!(expression)) { \
                _xbox_assert(_PDCLIB_symbol2string(expression), \
                             __FILE__, \
                             __func__, \
                             __LINE__); \
            } \
        } while(0)
#endif

#define static_assert _Static_assert

#ifdef __cplusplus
}
#endif
