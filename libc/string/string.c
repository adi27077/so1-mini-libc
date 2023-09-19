// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *p = destination;
	while (*source != '\0')
	{
		*p++ = *source++;
	}

	*p = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *p = destination;
	size_t count = 0;
	while (*source != '\0' && count <= len)
	{
		*p++ = *source++;
		count++;
	}

	*p = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *p = destination;
	while (*p != '\0')
	{
		p++;
	}

	while (*source != '\0')
	{
		*p++ = *source++;
	}

	*p = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *p = destination;
	while (*p != '\0')
	{
		p++;
	}

	size_t count = 0;
	while (*source != '\0' && count < len)
	{
		*p++ = *source++;
		count++;
	}

	*p = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}
	
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t count = 1;

	while (*str1 != '\0' && *str2 != '\0' && count < len)
	{
		if (*str1 != *str2)
		{
			return *str1 - *str2;
		}
		str1++;
		str2++;
		count++;
	}

	return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (; *str != '\0'; str++)
	{
		if (*str == c)
		{
			return (char *)str;
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *p = NULL;
	for (; *str != '\0'; str++)
	{
		if (*str == c)
		{
			p = (char *)str;
		}
	}

	return p;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	char *p = NULL;

	for (; *haystack != '\0'; haystack++)
	{
		if (*haystack == *needle)
		{
			p = (char *)haystack;
			for (; *needle != '\0'; needle++, haystack++)
			{
				if (*haystack != *needle)
				{
					p = NULL;
					break;
				}
			}
		}
	}

	return p;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *p = NULL;
	char *q = NULL;
	char *r = NULL;

	for (; *haystack != '\0'; haystack++)
	{
		if (*haystack == *needle)
		{
			p = (char *)haystack;
			q = (char *)needle;

			for (; *q != '\0'; q++, haystack++)
			{
				if (*haystack != *q)
				{
					p = NULL;
					break;
				}
			}

			if (p != NULL)
			{
				r = p;
			}

		}
	}

	return r;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = (char *)destination;
	char *s = (char *)source;

	while (num--)
	{
		*d++ = *s++;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = (char *)destination;
	char *s = (char *)source;

	/* Memory is not overlapping*/
	if (d <= s || d >= s + num)
	{
		while (num--)
		{
			*d++ = *s++;
		}
	}
	else /* Memory is overlapping */
	{
		d += num - 1;
		s += num - 1;
		while (num--)
		{
			*d-- = *s--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;

	while (num--)
	{
		if (*p1 != *p2)
		{
			return *p1 - *p2;
		}
		p1++;
		p2++;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *p = (char *)source;

	while (num--)
	{
		*p++ = value;
	}

	return source;
}
