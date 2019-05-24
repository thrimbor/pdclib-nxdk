/* _PDCLIB_open( const char * const, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_open() fit for use with nxdk
*/

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <hal/fileio.h>

int _PDCLIB_open( const char * const filename, unsigned int mode )
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
            return -1;
    }

    int status;
    int handle;

    status = XCreateFile(&handle, filename, access_flags, FILE_SHARE_READ | FILE_SHARE_WRITE, create_flags, FILE_FLAG_RANDOM_ACCESS);

    if (status == STATUS_SUCCESS || status == ERROR_ALREADY_EXISTS)
    {
        if (mode & _PDCLIB_FAPPEND)
        {
            int new_pos = 0;
            XSetFilePointer(handle, 0, &new_pos, FILE_END);
        }
        return handle;
    }
    else
    {
        // FIXME: Translate returned errors to proper errno
        //_PDCLIB_errno = _PDCLIB_ERROR;
        return -1;
    }
}

#endif
