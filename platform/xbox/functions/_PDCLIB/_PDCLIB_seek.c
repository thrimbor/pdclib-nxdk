/* int64_t _PDCLIB_seek( FILE *, int64_t, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_seek() for use with nxdk
 */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"
#include "pdclib/_PDCLIB_config.h"
#include <pdclib/werrno.h>

#include <winapi/fileapi.h>

_PDCLIB_int64_t _PDCLIB_seek( struct _PDCLIB_file_t * stream, _PDCLIB_int64_t offset, int whence )
{
    // nxdk is limited to 32 bit file pointers at the moment
    int method;
    switch ( whence )
    {
        case SEEK_SET: method = FILE_BEGIN; break;
        case SEEK_CUR: method = FILE_CURRENT; break;
        case SEEK_END: method = FILE_END; break;
        default:
            *_PDCLIB_errno_func() = werror_to_errno(GetLastError(), _PDCLIB_ERRNO_MAX + 1);
            return EOF;
    }

    DWORD new_pos = 0;
    new_pos =  SetFilePointer(stream->handle, offset, NULL, method);
    if(new_pos != INVALID_SET_FILE_POINTER) //Success
    {
        stream->ungetidx = 0;
        stream->bufidx = 0;
        stream->bufend = 0;
        stream->pos.offset = new_pos;
        return new_pos;
    }
    else
    {
        *_PDCLIB_errno_func() = werror_to_errno(GetLastError(), _PDCLIB_ERRNO_MAX + 1);
        return EOF;
    }
}

#endif
