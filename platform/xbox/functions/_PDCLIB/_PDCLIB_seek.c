/* int64_t _PDCLIB_seek( FILE *, int64_t, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_seek() for use with nxdk
 */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <errno.h>
#include <windows.h>

int _PDCLIB_w32errno( DWORD werror );

_PDCLIB_int64_t _PDCLIB_seek( struct _PDCLIB_file_t * stream, _PDCLIB_int64_t offset, int whence )
{
    int method;
    switch ( whence )
    {
        case SEEK_SET: method = FILE_BEGIN; break;
        case SEEK_CUR: method = FILE_CURRENT; break;
        case SEEK_END: method = FILE_END; break;
        default:
            *_PDCLIB_errno_func() = EINVAL;
            return EOF;
    }

    LARGE_INTEGER new_pos;
    new_pos.QuadPart = offset;
    if ( SetFilePointerEx( stream->handle, new_pos, &new_pos, method) )
    {
        stream->ungetidx = 0;
        stream->bufidx = 0;
        stream->bufend = 0;
        stream->pos.offset = new_pos.QuadPart;
        return new_pos.QuadPart;
    }
    else
    {
        *_PDCLIB_errno_func() = _PDCLIB_w32errno(GetLastError());
        return EOF;
    }
}

#endif
