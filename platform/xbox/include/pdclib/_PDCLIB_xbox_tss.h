#ifndef _PDCLIB_TSS_H
#define _PDCLIB_TSS_H _PDCLIB_TSS_H

#include <stdint.h>
#include <threads.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TSS_SLOTS_NUM 64

extern mtx_t tss_lock;
extern thread_local void *tss_slots[TSS_SLOTS_NUM];
extern tss_dtor_t tss_dtors[TSS_SLOTS_NUM];
extern uint32_t tss_bitmap[TSS_SLOTS_NUM / 32];

void _PDCLIB_xbox_tss_cleanup();
void _PDCLIB_xbox_tss_init();

#ifdef __cplusplus
}
#endif

#endif
