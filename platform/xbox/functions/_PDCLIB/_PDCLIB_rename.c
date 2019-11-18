/* _PDCLIB_rename( const char *, const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_rename() for use with nxdk
 */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <errno.h>
#include <windows.h>

int _PDCLIB_w32errno( DWORD werror );

int _PDCLIB_rename( const char * old, const char * new )
{
    if ( MoveFileA(old, new) )
    {
        return 0;
    }
    else
    {
        *_PDCLIB_errno_func() = _PDCLIB_w32errno(GetLastError());
        return -1;
    }
}

#endif
