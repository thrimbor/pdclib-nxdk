#include <threads.h>
#include <windows.h>

thrd_t thrd_current (void)
{
    return GetCurrentThread();
}
