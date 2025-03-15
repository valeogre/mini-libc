// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	// invoking the stat syscall and setting the errno in casse of an error
	int res = syscall(4, path, buf);
	if(0 > res)
	{
		errno = -res;
		return -1;
	}
	return res;
}
