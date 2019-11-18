/* _PDCLIB_open( const char * const, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_open() fit for use with nxdk
*/

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <errno.h>
#include <windows.h>

int _PDCLIB_w32errno( DWORD werror );

_PDCLIB_fd_t _PDCLIB_open( const char * const filename, unsigned int mode )
{
    int access_flags = 0;
    int create_flags = 0;

    switch ( mode & ( _PDCLIB_FREAD | _PDCLIB_FWRITE | _PDCLIB_FAPPEND | _PDCLIB_FRW ) )
    {
        case _PDCLIB_FREAD: /* "r" */
            access_flags = GENERIC_READ;
            create_flags = OPEN_EXISTING;
            break;
        case _PDCLIB_FWRITE: /* "w" */
            access_flags = GENERIC_WRITE;
            create_flags = CREATE_ALWAYS;
            break;
        case _PDCLIB_FWRITE | _PDCLIB_FAPPEND: /* "a" */
            access_flags = GENERIC_WRITE;
            create_flags = OPEN_ALWAYS;
            break;
        case _PDCLIB_FREAD | _PDCLIB_FRW: /* "r+" */
            access_flags = GENERIC_READ | GENERIC_WRITE;
            create_flags = OPEN_EXISTING;
            break;
        case _PDCLIB_FWRITE | _PDCLIB_FRW: /* "w+" */
            access_flags = GENERIC_READ | GENERIC_WRITE;
            create_flags = CREATE_ALWAYS | TRUNCATE_EXISTING;
            break;
        case _PDCLIB_FAPPEND | _PDCLIB_FRW: /* "a+" */
            access_flags = GENERIC_READ | GENERIC_WRITE;
            create_flags = OPEN_ALWAYS;
            break;
        default: /* Invalid mode */
            return INVALID_HANDLE_VALUE;
    }

    int status;
    HANDLE handle;

    handle = CreateFileA(filename, access_flags, FILE_SHARE_READ | FILE_SHARE_DELETE, NULL, create_flags, FILE_ATTRIBUTE_NORMAL, NULL);

    if (handle != INVALID_HANDLE_VALUE)
    {
        if (mode & _PDCLIB_FAPPEND)
        {
            LARGE_INTEGER new_pos;
            new_pos.QuadPart = 0;
            BOOL ok = SetFilePointerEx(handle, new_pos, &new_pos, FILE_END);
            if (!ok)
            {
                *_PDCLIB_errno_func() = _PDCLIB_w32errno(GetLastError());
                CloseHandle(handle);
                return INVALID_HANDLE_VALUE;
            }
        }
        return handle;
    }
    else
    {
        *_PDCLIB_errno_func() = _PDCLIB_w32errno(GetLastError());
        return INVALID_HANDLE_VALUE;
    }
}

#endif
