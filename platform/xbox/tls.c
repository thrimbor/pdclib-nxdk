#include <stdlib.h>
#include <winnt.h>

#pragma comment(linker, "/include:__tls_index")
ULONG _tls_index = 0;

__attribute__((section(".tls"))) char _tls_start = 0;
__attribute__((section(".tls$ZZZ"))) char _tls_end = 0;

const IMAGE_TLS_DIRECTORY_32 _tls_used =
{
    (DWORD) &_tls_start,
    (DWORD) &_tls_end,
    (DWORD) &_tls_index,
    (DWORD) NULL,
    (DWORD) 0,
    (DWORD) 0
};
