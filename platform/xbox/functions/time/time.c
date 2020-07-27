/* time( time_t * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <time.h>

#ifndef REGTEST

#include <xboxkrnl/xboxkrnl.h>
#define NT_EPOCH_TIME_OFFSET ((LONGLONG)(369 * 365 + 89) * 24 * 3600 * 10000000)

time_t time( time_t * timer )
{
    time_t result;
    LARGE_INTEGER cur_time;

    KeQuerySystemTime(&cur_time);
    cur_time.QuadPart -= NT_EPOCH_TIME_OFFSET;

    result = (time_t)(cur_time.QuadPart / 10000000);

    if (timer != NULL)
    {
        *timer = result;
    }

    return result;
}

#endif
