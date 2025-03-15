// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	// invoking the open syscall and setting the errno in case of an error
	int res = syscall(2, filename, flags, 0);
	if(0 > res)
	{
		errno = -res;
		return -1;
	}
	return res;
}
