#include <threads.h>
#include <windows.h>

int thrd_join (thrd_t thr, int *res)
{
    if (WaitForSingleObject(thr, INFINITE) == WAIT_FAILED) {
        return thrd_error;
    }

    if (res) {
        DWORD thread_result;
        if (GetExitCodeThread(thr, &thread_result) != 0) {
            *res = (int)thread_result;
        } else {
            return thrd_error;
        }
    }

    CloseHandle(thr);
    return thrd_success;
}
