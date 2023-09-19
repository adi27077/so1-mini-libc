// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	/* Allocate memory*/
	void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (start == MAP_FAILED)
		return NULL;

	/* Add the block to the list*/
	mem_list_add(start, size);
	return start;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = malloc(nmemb * size);
	if (ptr != NULL)
		memset(ptr, 0, nmemb * size);
	
	return ptr;
}

void free(void *ptr)
{
	if (ptr == NULL)
		return;

	struct mem_list *block = mem_list_find(ptr);

	/* Item was not allocated by malloc*/
	if (block == NULL)
		return;

	/* Free the memory*/
	munmap(block->start, block->len);

	/* Remove the block from the list*/
	mem_list_del(block->start);

}
	

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(size);

	struct mem_list *item = (struct mem_list *)ptr;

	/* Item was not allocated by malloc*/
	if (item == NULL)
		return NULL;

	/* The size is smaller/equal than the current one so no changes are made to the memory block*/
	if (size <= item->len)
		return ptr;

	/* Allocate a new block with the given size*/
	void *new_ptr = malloc(size);
	if (new_ptr == NULL)
		return NULL;

	/* Copy the data from the old block to the new one*/
	memcpy(new_ptr, ptr, item->len);

	/* Free the old block*/
	free(ptr);
	
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb == 0 || size == 0)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(nmemb * size);

	size_t new_size = nmemb * size;

	return realloc(ptr, new_size);
}
