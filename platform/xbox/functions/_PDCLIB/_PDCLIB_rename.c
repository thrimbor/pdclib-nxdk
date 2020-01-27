/* _PDCLIB_rename( const char *, const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_rename() for use with nxdk
 */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"
#include <pdclib/werrno.h>

#include <winapi/fileapi.h>

int _PDCLIB_rename( const char * old, const char * new )
{
    if (MoveFileA(old, new) != 0)
    {
        return 0;
    }
    else
    {
        *_PDCLIB_errno_func() = werror_to_errno(GetLastError(), _PDCLIB_ERRNO_MAX + 1);
        return -1;
    }
}

#endif
