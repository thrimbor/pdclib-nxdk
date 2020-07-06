#include <threads.h>
#include <stdbool.h>
#include <windows.h>

int thrd_equal (thrd_t thr0, thrd_t thr1)
{
    return (GetThreadId(thr0) == GetThreadId(thr1));
}
