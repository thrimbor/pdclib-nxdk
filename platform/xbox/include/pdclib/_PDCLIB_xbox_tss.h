#ifndef _PDCLIB_TSS_H
#define _PDCLIB_TSS_H _PDCLIB_TSS_H

#include <threads.h>
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

void _PDCLIB_xbox_tss_cleanup (void);

extern tss_dtor_t tss_dtors[FLS_MAXIMUM_AVAILABLE];

#ifdef __cplusplus
}
#endif

#endif
