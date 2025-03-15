// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	// invoking the stat syscall and setting the errno in case of an error
	int res = syscall(5, fd, st);
	if(0 > res)
	{
		errno = -res;
		return -1;
	}
	return res;
}
