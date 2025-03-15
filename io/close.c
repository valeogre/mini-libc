// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	// invoking the close syscall and setting the errno in case of an error
	int res = syscall(3, fd);
	if (0 > res)
	{
		errno = -res;
		return -1;
	}
	return res;
}
