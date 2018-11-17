/* _PDCLIB_rename( const char *, const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_rename() for use with nxdk
 */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <hal/fileio.h>

int _PDCLIB_rename( const char * old, const char * new )
{
    if (XRenameFile(old, new) == STATUS_SUCCESS)
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
