/* remove( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of remove() for nxdk
*/

#include <stdio.h>

#ifndef REGTEST

#include <errno.h>
#include <string.h>

#include <windows.h>

int _PDCLIB_w32errno( DWORD werror );

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

    if ( DeleteFileA( pathname ) )
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
