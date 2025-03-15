// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	// dest_ptr is a pointer for the start of the solution
	char *dest_ptr = destination;
	// copy each character until the '\0' character
	while ((*dest_ptr++ = *source++))
		;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	// dest_ptr is a pointer for the start of the solution
	char *dest_ptr = destination;
	// cop each character until the source ends or len is zero
	while ((*dest_ptr++ = *source++) && (len--))
		;
	*dest_ptr = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *dest_ptr = destination;
	// i move to the end of the destination and copy each character
	while (*dest_ptr)
	{
		dest_ptr++;
	}

	while (*source)
	{
		*dest_ptr++ = *source++;
	}

	*dest_ptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *dest_ptr = destination;
	while (*dest_ptr)
	{
		dest_ptr++;
	}
	// copy characters until the end of the source string or len is 0
	while ((*source) && (len--))
	{
		*dest_ptr++ = *source++;
	}

	*dest_ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	// check the strings until there is a different character
	while (*str1 == *str2)
	{
		// if both strings reach the end at the same time they are equal
		if ((*str1 == '\0') && (*str2 == '\0'))
		{
			return 0;
		}
		str1++;
		str2++;
	}
	// return the differrence of the first different characters
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	// checking the same way as in the strcmp, but only the first n characters
	while (*str1 == *str2 && len)
	{
		if ((*str1 == '\0') && (*str2 == '\0'))
		{
			return 0;
		}
		str1++;
		str2++;
		len--;
	}
	if (0 == len)
	{
		return 0;
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
	// comparing each character of the string until it matches c
	for (; *str != '\0'; str++)
	{
		if ((char)c == *str)
		{
			return (char *)str;
		}
	}

	if (c == '\0')
	{
		return (char *)str;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *last = NULL;
	/* comparing each character and updating the pointer for the last
	appeareance of c*/
	while (*str)
	{
		if (*str == (char)c)
		{
			last = str;
		}
		str++;
	}
	// case for c being the ending character
	if (c == '\0')
	{
		return (char *)str;
	}

	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	for (; *haystack; haystack++)
	{
		// using two pointers, i check if the substring is found in the string
		const char *needle_copy = needle;
		const char *haystack_copy = haystack;
		while ((*needle_copy == *haystack_copy) && (*needle_copy) &&
			   (*haystack_copy))
		{
			needle_copy++;
			haystack_copy++;
		}
		if (!*needle_copy)
		{
			return (char *)haystack;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	// pointer for the last substring occurence
	const char *last = NULL;
	for (; *haystack; haystack++)
	{
		const char *needle_copy = needle;
		const char *haystack_copy = haystack;
		// using two pointers, i check if the substring is found in the string
		while ((*needle_copy == *haystack_copy) && (*needle_copy) &&
			   (*haystack_copy))
		{
			needle_copy++;
			haystack_copy++;
		}
		if (!*needle_copy)
		{
			// update the last occurence of the substring
			last = (char *)haystack;
		}
	}
	return (char *)last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_copy = destination;
	const char *source_copy = source;
	size_t i;
	// copying each bite
	for (i = 0; i < num; i++)
	{
		dest_copy[i] = source_copy[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest_copy = destination;
	const char *source_copy = source;
	size_t i;
	// making sure the blocks dont overlap
	if (dest_copy < source_copy)
	{
		// copying forward, no overlap
		for (i = 0; i < num; i++)
		{
			dest_copy[i] = source_copy[i];
		}
	} else {
		// backwards when there is overlap
		for (i = num; i > 0; i--)
		{
			dest_copy[i - 1] = source_copy[i - 1];
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *p1 = ptr1;
	const char *p2 = ptr2;

	size_t i;
	// comparing each  byte of memory
	for (i = 0; i < num; i++)
	{
		if (p1[i] != p2[i])
		{
			// returning the difference if the bytes differ
			return p1[i] - p2[i];
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *ptr = source;
	size_t i;
	// for each byte in the block setting it to the given value
	for (i = 0; i < num; i++)
	{
		ptr[i] = value;
	}
	return source;
}
