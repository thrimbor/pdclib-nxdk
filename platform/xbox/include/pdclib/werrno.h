#ifndef _XPDCLIB_WERRNO_H_
#define _XPDCLIB_WERRNO_H_

#include <errno.h>

errno_t werror_to_errno(DWORD werror, errno_t fallback_errno);

#endif
