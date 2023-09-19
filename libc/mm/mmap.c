// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	void *mem = 0;

	mem = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if ((long)mem < 0)
	{
		errno = - (int)mem;
		return MAP_FAILED;
	}

	return mem;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *mem = 0;

	mem = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if ((long)mem < 0)
	{
		errno = - (int)mem;
		return MAP_FAILED;
	}

	return mem;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int ret = syscall(__NR_munmap, addr, length);

	if (ret < 0)
	{
		errno = - ret;
		return -1;
	}

	return ret;
}
