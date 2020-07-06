#include <threads.h>
#include <assert.h>
#include <windows.h>

void *tss_get (tss_t key)
{
    return TlsGetValue(key);
}
