#include <threads.h>
#include <windows.h>

void thrd_yield (void)
{
    SwitchToThread();
}
