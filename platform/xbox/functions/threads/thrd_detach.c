#include <threads.h>
#include <windows.h>

int thrd_detach (thrd_t thr)
{
    if (CloseHandle(thr)) {
        return thrd_success;
    }

    return thrd_error;
}
