#include <pdclib/_PDCLIB_xbox_tss.h>
#include <stdbool.h>
#include <threads.h>
#include <windows.h>

tss_dtor_t tss_dtors[FLS_MAXIMUM_AVAILABLE];

void _PDCLIB_xbox_tss_cleanup (void)
{
    for (int dtor_i = 0; dtor_i < TSS_DTOR_ITERATIONS; dtor_i++) {
        for (int i = 0; i < FLS_MAXIMUM_AVAILABLE; i++) {
            if (!tss_dtors[i]) continue;
            if (!TlsGetValue(i)) continue;

            void *val = TlsGetValue(i);
            TlsSetValue(i, NULL);
            tss_dtors[i](val);
        }

        bool done = true;

        for (int i = 0; i < FLS_MAXIMUM_AVAILABLE; i++) {
            if (tss_dtors[i] && TlsGetValue(i)) {
                done = false;
                break;
            }
        }

        if (done) break;
    }
}
