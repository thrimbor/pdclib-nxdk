#include <xboxkrnl/xboxkrnl.h>
#include <stdlib.h>
#include <threads.h>
#include <pdclib/_PDCLIB_xbox_tls.h>
#include <pdclib/_PDCLIB_xbox_tss.h>

extern void _PDCLIB_xbox_run_crt_initializers();
extern int main (int argc, char **argv);
extern mtx_t _PDCLIB_filelist_mtx;
extern struct _PDCLIB_file_t * stdin;
extern struct _PDCLIB_file_t * stdout;
extern struct _PDCLIB_file_t * stderr;

void _PDCLIB_xbox_libc_init ()
{
    mtx_init(&_PDCLIB_filelist_mtx, mtx_plain);
    mtx_init(&stdin->mtx, mtx_recursive);
    mtx_init(&stdout->mtx, mtx_recursive);
    mtx_init(&stderr->mtx, mtx_recursive);
}

void _PDCLIB_xbox_libc_deinit ()
{
    mtx_destroy(&_PDCLIB_filelist_mtx);
    mtx_destroy(&stdin->mtx);
    mtx_destroy(&stdout->mtx);
    mtx_destroy(&stderr->mtx);
}

static int main_wrapper ()
{
    _PDCLIB_xbox_tss_init();

    _PDCLIB_xbox_libc_init();

    _PDCLIB_xbox_run_crt_initializers();

    int retval;
    char *_argv = 0;
    retval = main(0, &_argv);

    _PDCLIB_xbox_libc_deinit();

    exit(retval);

    return retval;
}

void XboxCRTEntry ()
{
    DWORD tlssize;
    // Sum up the required amount of memory, round it up to a multiple of
    // 16 bytes and add 4 bytes for the self-reference
    tlssize = (_tls_used.EndAddressOfRawData - _tls_used.StartAddressOfRawData) + _tls_used.SizeOfZeroFill;
    tlssize = (tlssize + 15) & ~15;
    tlssize += 4;
    *((DWORD *)_tls_used.AddressOfIndex) = (int)tlssize / -4;

    thrd_t main_thread;
    thrd_create(&main_thread, main_wrapper, NULL);
    thrd_detach(main_thread);
}
