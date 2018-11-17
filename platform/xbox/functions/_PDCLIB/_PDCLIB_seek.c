/* int64_t _PDCLIB_seek( FILE *, int64_t, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_seek() for use with nxdk
 */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <hal/fileio.h>

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
            // FIXME: Translate returned errors to proper errno
            //_PDCLIB_errno = _PDCLIB_ERROR;
            return EOF;
    }

    int new_pos = 0;
    if (XSetFilePointer(stream->handle, offset, &new_pos, method))
    {
        stream->ungetidx = 0;
        stream->bufidx = 0;
        stream->bufend = 0;
        stream->pos.offset = new_pos;
        return new_pos;
    }
    else
    {
        // FIXME: Translate returned errors to proper errno
        //_PDCLIB_errno = _PDCLIB_ERROR;
        return EOF;
    }
}

#endif
