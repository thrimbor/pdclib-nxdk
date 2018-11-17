/* remove( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of remove() for nxdk
*/

#include <stdio.h>

#ifndef REGTEST

#include <string.h>

#include <hal/fileio.h>

extern struct _PDCLIB_file_t * _PDCLIB_filelist;

int remove( const char * pathname )
{
    int rc;

    struct _PDCLIB_file_t * current = _PDCLIB_filelist;
    while ( current != NULL )
    {
        if ( ( current->filename != NULL ) && ( strcmp( current->filename, pathname ) == 0 ) )
        {
            return EOF;
        }
        current = current->next;
    }

    if ( XDeleteFile( pathname ) == STATUS_SUCCESS )
    {
        return 0;
    }
    else
    {
        // FIXME: Translate returned errors to proper errno
        //_PDCLIB_errno = _PDCLIB_ERROR;
        return -1;
    }
}

#endif
