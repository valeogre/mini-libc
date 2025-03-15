// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	// invoking the ftruncate syscall and setting the errno in case of an error
	int res = syscall(77, fd, length);
	if (0 > res)
	{
		errno = -res;
		return -1;
	}
	return 0;
}
