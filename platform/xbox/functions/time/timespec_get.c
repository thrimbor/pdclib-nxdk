/* timespec_get( struct timespec *, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <time.h>

#ifndef REGTEST

#include <xboxkrnl/xboxkrnl.h>

int timespec_get( struct timespec * ts, int base )
{
    if ( base == TIME_UTC )
    {
        LARGE_INTEGER cur_time;

        KeQuerySystemTime(&cur_time);

        ts->tv_sec = cur_time.QuadPart / 10000000;
        ts->tv_nsec = (cur_time.QuadPart % 10000000) * 100;

        return base;
    }

    /* Not supporting any other time base than TIME_UTC for now. */
    return 0;
}

#endif
