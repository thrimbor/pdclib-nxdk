#include <threads.h>
#include <assert.h>
#include <string.h>
#include <pdclib/_PDCLIB_xbox_tls.h>
#include <xboxkrnl/xboxkrnl.h>

static VOID NTAPI _PDCLIB_xbox_thread_startup (PKSTART_ROUTINE StartRoutine, PVOID StartContext);

int thrd_create (thrd_t *thr, thrd_start_t func, void *arg)
{
    if (thr == NULL) {
        return thrd_error;
    }

    NTSTATUS ntstatus;
    ULONG stacksize;
    ULONG tlssize;
    // FIXME: We're directly reading the XBE StackCommit field here.
    //        A cleaner way with proper structs would be nice.
    stacksize = *((ULONG *)0x00010130);
    // Sum up the required amount of memory, round it up to a multiple of
    // 16 bytes and add 4 bytes for the self-reference
    tlssize = (_tls_used.EndAddressOfRawData - _tls_used.StartAddressOfRawData) + _tls_used.SizeOfZeroFill;
    tlssize = (tlssize + 15) & ~15;
    tlssize += 4;
    ntstatus = PsCreateSystemThreadEx(&thr->handle, 0, stacksize, tlssize, &thr->id, (PKSTART_ROUTINE)func, arg, FALSE, FALSE, _PDCLIB_xbox_thread_startup);

    if (NT_SUCCESS(ntstatus))
    {
        return thrd_success;
    }

    return thrd_error;
}

VOID NTAPI _PDCLIB_xbox_thread_startup (PKSTART_ROUTINE StartRoutine, PVOID StartContext)
{
    // Make sure the TLS pointer is valid
    assert(KeGetCurrentThread()->TlsData);

    // Retrieve TLS area address and point first entry to itself
    DWORD *TlsData;
    TlsData = ((DWORD *)KeGetCurrentThread()->TlsData) + 1;
    TlsData[-1] = (DWORD)TlsData;

    // 16 byte alignment required
    assert(((DWORD)TlsData & 15) == 0);

    // Copy initial values of TLS area
    DWORD TlsDataSize;
    TlsDataSize = _tls_used.EndAddressOfRawData - _tls_used.StartAddressOfRawData;
    memcpy(TlsData, (void *)_tls_used.StartAddressOfRawData, TlsDataSize);

    // Zero-initialize the rest
    RtlZeroMemory((char *)TlsData + TlsDataSize, _tls_used.SizeOfZeroFill);

    int res;
    res = ((thrd_start_t)StartRoutine)(StartContext);
    thrd_exit(res);
}
