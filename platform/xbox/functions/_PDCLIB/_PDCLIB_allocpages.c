/* _PDCLIB_allocpages( int const )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_allocpages() for use with nxdk
*/

#include <stdint.h>
#include <stddef.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"
#include <xboxkrnl/xboxkrnl.h>

void * _PDCLIB_allocpages( int const n )
{
    void *targetAddress = NULL;
    unsigned int size = n * _PDCLIB_PAGESIZE;
    NTSTATUS status;

    status = NtAllocateVirtualMemory(&targetAddress, 0, &size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    if (NT_SUCCESS(status))
    {
        return targetAddress;
    }
    else
    {
        return NULL;
    }
}

#endif
