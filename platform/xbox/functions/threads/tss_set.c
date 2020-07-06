#include <threads.h>
#include <assert.h>
#include <windows.h>

int tss_set (tss_t key, void *val)
{
    if (TlsSetValue(key, val)) {
        return thrd_success;
    }

    return thrd_error;
}
