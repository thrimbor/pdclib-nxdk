/* _PDCLIB_fillbuffer( struct _PDCLIB_file_t * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_fillbuffer() for use with nxdk
*/

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"
#include <pdclib/werrno.h>

#include <winapi/fileapi.h>
#include <winapi/winerror.h>

int _PDCLIB_fillbuffer( struct _PDCLIB_file_t * stream )
{
    /* No need to handle buffers > INT_MAX, as PDCLib doesn't allow them */
    int status;
    DWORD amount_read;

    status = ReadFile(stream->handle, stream->buffer, stream->bufsize, &amount_read, NULL);
    if (status)
    {
        if (amount_read == 0)
        {
            /* End-of-File */
            stream->status |= _PDCLIB_EOFFLAG;
            return EOF;
        }

        /* Reading successful. */
        if ( ! ( stream->status & _PDCLIB_FBIN ) )
        {
            /* TODO: Text stream conversion here */
        }
        stream->pos.offset += amount_read;
        stream->bufend = amount_read;
        stream->bufidx = 0;
        return 0;
    }
    else
    {
        DWORD error;

        error = GetLastError();
        *_PDCLIB_errno_func() = werror_to_errno(error, _PDCLIB_ERRNO_MAX + 1);

        if(error == ERROR_HANDLE_EOF)
            stream->status |= _PDCLIB_EOFFLAG;
        else
            stream->status |= _PDCLIB_ERRORFLAG;
        return EOF;
    }
}

#endif
