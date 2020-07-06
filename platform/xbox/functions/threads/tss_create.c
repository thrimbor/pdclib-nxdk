#include <threads.h>
#include <assert.h>
#include <stdbool.h>
#include <windows.h>
#include <xboxkrnl/xboxkrnl.h>
#include <pdclib/_PDCLIB_xbox_tss.h>

int tss_create (tss_t *key, tss_dtor_t dtor)
{
    *key = TlsAlloc();
    if (*key == TLS_OUT_OF_INDEXES) {
        return thrd_error;
    }

    tss_dtors[*key] = dtor;
    return thrd_success;
}
