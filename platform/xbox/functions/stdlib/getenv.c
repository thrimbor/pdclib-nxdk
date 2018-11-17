/* getenv( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an example implementation of getenv() fit for use with POSIX kernels.
*/

#include <string.h>
#include <stdlib.h>

#ifndef REGTEST

char * getenv( const char * name )
{
    return NULL;
}

#endif
