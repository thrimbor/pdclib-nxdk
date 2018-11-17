/* _PDCLIB_Exit( int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an implementation of _PDCLIB_Exit() for use with nxdk
*/

#include <stdlib.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"
#include <xboxkrnl/xboxkrnl.h>

void _PDCLIB_Exit( int status )
{
    HalReturnToFirmware( HalQuickRebootRoutine );
}

#endif
