// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (0 == size)
	{
		return NULL;
	}
	/* memory allocation for a positive size
	using mmap function as a request(syscall)*/
	void *mem_pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (mem_pointer == (void *)-1)
	{
		return NULL;
	}
	// adding the new memory block to the memory list
	mem_list_add(mem_pointer, size);
	// returns pointer to the memory block
	return mem_pointer;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total = size * nmemb;
	if (0 == size)
	{
		return NULL;
	}
	/* memory allocation for a positive size
	using mmap function as a OS request(syscall)*/
	void *mem_pointer = mmap(NULL, total, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (mem_pointer)
	{
		// initializing the memory block to 0
		memset(mem_pointer, 0, total);
	}
	// adding the new memory block to the memory list
	mem_list_add(mem_pointer, size);
	// returns pointer to the memory block
	return mem_pointer;
}

void free(void *ptr)
{
	if (NULL == ptr)
	{
		return;
	}
	// if the pointer isn't NULL, find the memory block
	struct mem_list *block_address = mem_list_find(ptr);
	if (NULL == block_address)
	{
		return;
	}
	// unmaping and removing the memory block from the memory linked list
	munmap(block_address->start, block_address->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	if (0 == size)
	{
		free(ptr);
		return NULL;
	}
	// finds the initial block of memory in the list
	struct mem_list *block_address = mem_list_find(ptr);
	if (NULL == block_address)
	{
		return NULL;
	}
	/* allocation of a new memory block, where i copy information from 
	the source pointer, in this case, ptr. i use the smaller one of the 
	old size or the new memory block size */
	size_t old_size = block_address->len;
	void *new_block_address = malloc(size);
	if (size < old_size)
	{
		memcpy(new_block_address, ptr, size);
	} else {
		memcpy(new_block_address, ptr, old_size);
	}
	// free the old memory block and return the new address
	free(ptr);
	return new_block_address;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	// realloc memory for the new total size
	if (0 == total)
	{
		free(ptr);
		return NULL;
	}
	// finds the initial block of memory in the list
	struct mem_list *block_address = mem_list_find(ptr);
	if (NULL == block_address)
	{
		return NULL;
	}
	/* allocation of a new memory block, where i copy information from 
	the source pointer, in this case, ptr. i use the smaller one of the 
	old size or the new memory block size */
	size_t old_size = block_address->len;
	void *new_block_address = malloc(size);
	if (total < old_size)
	{
		memcpy(new_block_address, ptr, total);
	} else {
		memcpy(new_block_address, ptr, old_size);
	}
	// free the old memory block and return the new address
	free(ptr);
	return new_block_address;
}
