#ifndef _PDCLIB_TLS_H
#define _PDCLIB_TLS_H _PDCLIB_TLS_H

#include <xboxkrnl/xboxkrnl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _IMAGE_TLS_DIRECTORY
{
    DWORD StartAddressOfRawData;
    DWORD EndAddressOfRawData;
    DWORD AddressOfIndex;
    DWORD AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY;
extern const IMAGE_TLS_DIRECTORY _tls_used;

#ifdef __cplusplus
}
#endif

#endif
