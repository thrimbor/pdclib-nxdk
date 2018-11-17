#include <threads.h>
#include <pdclib/_PDCLIB_xbox_tss.h>

void _PDCLIB_xbox_tss_init()
{
    mtx_init(&tss_lock, mtx_plain);
}
