// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	// invoking the lseek syscall and setting the errno in case of an error
	int res = syscall(8, fd, offset, whence);
	if (0 > res)
	{
		errno = -res;
		return -1;
	}
	return res;
}
