// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	// memory mapping using mmap syscall, modifies the errno if mapping fails
	long long res = syscall(9, addr, length, prot, flags, fd, offset);

	if (0 > res)
	{
		errno = -res;
		return (void *)-1;
	}
	// return pointer to mapped area in the virtual address space
	return (void *)res;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	// resizing the memory block using the mremap syscall
	long long res = syscall(25, old_address, old_size, new_size, flags);

	if (0 > res)
	{
		errno = -res;
		return (void *)-1;
	}
	// if the syscall didn't fail, returns the address of the resized VAS block
	return (void *)res;
}

int munmap(void *addr, size_t length)
{
	// unmap the memory sequence by syscall
	int res = syscall(11, addr, length);

	if (0 > res)
	{
		errno = -res;
		return -1;
	}
	// return 0 indicating the sucess of the syscall
	return 0;
}
