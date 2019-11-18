/* _PDCLIB_w32errno( DWORD )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef REGTEST
#include <errno.h>
#include <windows.h>

int _PDCLIB_w32errno( DWORD werror )
{
    switch ( werror )
    {
        case ERROR_ACCESS_DENIED: return EACCES;
        case ERROR_ACTIVE_CONNECTIONS: return EAGAIN;
        case ERROR_ALREADY_EXISTS: return EEXIST;
        case ERROR_BAD_LENGTH: return EINVAL;
        case ERROR_BAD_DEVICE: return ENODEV;
        case ERROR_BAD_EXE_FORMAT: return ENOEXEC;
        case ERROR_BAD_NETPATH: return ENOENT;
        case ERROR_BAD_NET_NAME: return ENOENT;
        case ERROR_BAD_NET_RESP: return ENOSYS;
        case ERROR_BAD_PATHNAME: return ENOENT;
        case ERROR_BAD_PIPE: return EINVAL;
        case ERROR_BAD_UNIT: return ENODEV;
        case ERROR_BAD_USERNAME: return EINVAL;
        case ERROR_BEGINNING_OF_MEDIA: return EIO;
        case ERROR_BROKEN_PIPE: return EPIPE;
        case ERROR_BUSY: return EBUSY;
        case ERROR_BUS_RESET: return EIO;
        case ERROR_CALL_NOT_IMPLEMENTED: return ENOSYS;
        case ERROR_CANCELLED: return EINTR;
        case ERROR_CANNOT_MAKE: return EPERM;
        case ERROR_CHILD_NOT_COMPLETE: return EBUSY;
        case ERROR_COMMITMENT_LIMIT: return EAGAIN;
        case ERROR_CONNECTION_REFUSED: return ECONNREFUSED;
        case ERROR_CRC: return EIO;
        case ERROR_DEVICE_DOOR_OPEN: return EIO;
        case ERROR_DEVICE_IN_USE: return EAGAIN;
        case ERROR_DEVICE_REQUIRES_CLEANING: return EIO;
        case ERROR_DEV_NOT_EXIST: return ENOENT;
        case ERROR_DIRECTORY: return ENOTDIR;
        case ERROR_DIR_NOT_EMPTY: return ENOTEMPTY;
        case ERROR_DISK_CORRUPT: return EIO;
        case ERROR_DISK_FULL: return ENOSPC;
        case ERROR_DS_GENERIC_ERROR: return EIO;
        case ERROR_DUP_NAME: return EEXIST;
        case ERROR_EAS_DIDNT_FIT: return ENOSPC;
        case ERROR_EAS_NOT_SUPPORTED: return ENOTSUP;
        case ERROR_EA_LIST_INCONSISTENT: return EINVAL;
        case ERROR_EA_TABLE_FULL: return ENOSPC;
        case ERROR_END_OF_MEDIA: return ENOSPC;
        case ERROR_EOM_OVERFLOW: return EIO;
        case ERROR_EXE_MACHINE_TYPE_MISMATCH: return ENOEXEC;
        case ERROR_EXE_MARKED_INVALID: return ENOEXEC;
        case ERROR_FILEMARK_DETECTED: return EIO;
        case ERROR_FILENAME_EXCED_RANGE: return ENAMETOOLONG;
        case ERROR_FILE_CORRUPT: return EEXIST;
        case ERROR_FILE_EXISTS: return EEXIST;
        case ERROR_FILE_INVALID: return ENXIO;
        case ERROR_FILE_NOT_FOUND: return ENOENT;
        case ERROR_HANDLE_DISK_FULL: return ENOSPC;
        case ERROR_HANDLE_EOF: return ENODATA;
        case ERROR_INVALID_ADDRESS: return EINVAL;
        case ERROR_INVALID_AT_INTERRUPT_TIME: return EINTR;
        case ERROR_INVALID_BLOCK_LENGTH: return EIO;
        case ERROR_INVALID_DATA: return EINVAL;
        case ERROR_INVALID_DRIVE: return ENOENT;
        case ERROR_INVALID_EA_NAME: return EINVAL;
        case ERROR_INVALID_EXE_SIGNATURE: return ENOEXEC;
        case ERROR_INVALID_FUNCTION: return ENOENT;
        case ERROR_INVALID_HANDLE: return EBADF;
        case ERROR_INVALID_NAME: return ENOENT;
        case ERROR_INVALID_PARAMETER: return EINVAL;
        case ERROR_INVALID_SIGNAL_NUMBER: return EINVAL;
        case ERROR_IOPL_NOT_ENABLED: return ENOEXEC;
        case ERROR_IO_DEVICE: return EIO;
        case ERROR_IO_INCOMPLETE: return EAGAIN;
        case ERROR_IO_PENDING: return EAGAIN;
        case ERROR_LOCK_VIOLATION: return EBUSY;
        case ERROR_MAX_THRDS_REACHED: return EAGAIN;
        case ERROR_META_EXPANSION_TOO_LONG: return EINVAL;
        case ERROR_MOD_NOT_FOUND: return ENOENT;
        case ERROR_MORE_DATA: return EMSGSIZE;
        case ERROR_NEGATIVE_SEEK: return EINVAL;
        case ERROR_NETNAME_DELETED: return ENOENT;
        case ERROR_NOACCESS: return EFAULT;
        case ERROR_NONE_MAPPED: return EINVAL;
        case ERROR_NONPAGED_SYSTEM_RESOURCES: return EAGAIN;
        case ERROR_NOT_CONNECTED: return ENOLINK;
        case ERROR_NOT_ENOUGH_MEMORY: return ENOMEM;
        case ERROR_NOT_ENOUGH_QUOTA: return EIO;
        case ERROR_NOT_OWNER: return EPERM;
        case ERROR_NOT_READY: return EBUSY;
        case ERROR_NOT_SAME_DEVICE: return EXDEV;
        case ERROR_NOT_SUPPORTED: return ENOSYS;
        case ERROR_NO_DATA: return EPIPE;
        case ERROR_NO_DATA_DETECTED: return EIO;
        case ERROR_NO_MEDIA_IN_DRIVE: return EPIPE;
        case ERROR_NO_MORE_FILES: return ENODATA;
        case ERROR_NO_MORE_ITEMS: return ENODATA;
        case ERROR_NO_MORE_SEARCH_HANDLES: return ENFILE;
        case ERROR_NO_PROC_SLOTS: return EAGAIN;
        case ERROR_NO_SIGNAL_SENT: return EIO;
        case ERROR_NO_SYSTEM_RESOURCES: return EFBIG;
        case ERROR_NO_TOKEN: return EINVAL;
        case ERROR_OPEN_FAILED: return EIO;
        case ERROR_OPEN_FILES: return EAGAIN;
        case ERROR_OUTOFMEMORY: return ENOMEM;
        case ERROR_PAGED_SYSTEM_RESOURCES: return EAGAIN;
        case ERROR_PAGEFILE_QUOTA: return EAGAIN;
        case ERROR_PATH_NOT_FOUND: return ENOENT;
        case ERROR_PIPE_BUSY: return EBUSY;
        case ERROR_PIPE_CONNECTED: return EBUSY;
        case ERROR_PIPE_LISTENING: return EPIPE;
        case ERROR_PIPE_NOT_CONNECTED: return EEXIST;
        case ERROR_POSSIBLE_DEADLOCK: return EDEADLK;
        case ERROR_PRIVILEGE_NOT_HELD: return EPERM;
        case ERROR_PROCESS_ABORTED: return EFAULT;
        case ERROR_PROC_NOT_FOUND: return ESRCH;
        case ERROR_REM_NOT_LIST: return EHOSTUNREACH;
        case ERROR_SECTOR_NOT_FOUND: return EINVAL;
        case ERROR_SEEK: return EINVAL;
        case ERROR_SERVICE_REQUEST_TIMEOUT: return EBUSY;
        case ERROR_SETMARK_DETECTED: return EIO;
        case ERROR_SHARING_BUFFER_EXCEEDED: return ENOLCK;
        case ERROR_SHARING_VIOLATION: return EBUSY;
        case ERROR_SIGNAL_PENDING: return EBUSY;
        case ERROR_SIGNAL_REFUSED: return EIO;
        case ERROR_SXS_CANT_GEN_ACTCTX: return ENOENT;
        case ERROR_THREAD_1_INACTIVE: return EINVAL;
        case ERROR_TIMEOUT: return EBUSY;
        case ERROR_TOO_MANY_LINKS: return EMLINK;
        case ERROR_TOO_MANY_OPEN_FILES: return EMFILE;
        case ERROR_UNEXP_NET_ERR: return EIO;
        case ERROR_WAIT_NO_CHILDREN: return ECHILD;
        case ERROR_WORKING_SET_QUOTA: return EAGAIN;
        case ERROR_WRITE_PROTECT: return EROFS;
        default: return ENOSYS;
    }
}

#endif

#ifdef TEST
#include "_PDCLIB_test.h"

int main( void )
{
    return TEST_RESULTS;
}

#endif
