#include <threads.h>
#include <pdclib/_PDCLIB_xbox_tss.h>
#include <xboxkrnl/xboxkrnl.h>

_Noreturn void thrd_exit (int res)
{
    _PDCLIB_xbox_tss_cleanup();
    PsTerminateSystemThread(res);
}
