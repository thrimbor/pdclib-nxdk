#include <threads.h>
#include <assert.h>
#include <windows.h>
#include <pdclib/_PDCLIB_xbox_tss.h>

void tss_delete (tss_t key)
{
    TlsFree(key);
    tss_dtors[key] = NULL;
}
