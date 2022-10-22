#include <stdio.h> /* size_t */
#include <assert.h> /* assert */
#include "wbo1.h"

#define WORDSIZE (sizeof(size_t))
#define BYTE (8)
#define CHAR (1)

static void CopyBytes(void *str, int ch, size_t n);

void *Memset(void *dest, int c, size_t size_to_fill)
{
	size_t c_block = 0;
	size_t reminder = 0;
	size_t loop = 0;
	size_t block_num = 0;
	size_t i = 0;
	void *ptr = dest;
	
	assert(NULL != dest);

	for(i = 0; i < WORDSIZE; ++i)
	{
		c_block <<= BYTE;
		c_block |= (char)c;
	}

	reminder = (size_t)dest % WORDSIZE;
	loop = WORDSIZE - reminder;
	CopyBytes(dest,c,loop); 

	*(char **)&dest += reminder;
	size_to_fill -= reminder;
	
	block_num = size_to_fill / WORDSIZE;

	for(i = 0; i < block_num; ++i)
	{
		*(size_t *)dest = c_block;
		++(*(size_t **)&dest);
	}
	
	*(size_t **)&dest += block_num;
	size_to_fill -= block_num * WORDSIZE;
	
	CopyBytes(dest, c, size_to_fill);

	return ptr;
}

static void CopyBytes(void *str, int ch, size_t n)
{
	size_t index = 0;
	assert(NULL != str);
	for(index = 0; index < n; ++index)
	{
		*(char *)str = (char)ch;
		++(*(char **)&str);
	}
}



void *Memcpy(void *dest, const void *source, size_t size_to_copy)
{
	assert(NULL != source);
	assert(NULL != dest);
	
	while(WORDSIZE <= size_to_copy)
	{
		*(size_t*)dest = *(size_t*)source;
        ++(*(char **)&dest);
        ++(*(char **)&source);
		size_to_copy = size_to_copy - WORDSIZE;
	}
	
	while(0 < size_to_copy)
	{
		*(char*)dest = *(char*)source;
        ++(*(char **)&dest);
        ++(*(char **)&source);
		size_to_copy = size_to_copy - CHAR;
	}
	return dest;
	
}

void *Memmove(void *dest, const void *source, size_t size_to_copy)
{
	size_t i = 0;
	size_t flag = 1;
	
	assert(NULL != source);
	assert(NULL != dest);
	
	if(dest == source)
	{
		return dest;
	}
	
	if(dest > source)
	{
		*(char**)&dest += size_to_copy - 1;
		*(char**)&source += size_to_copy - 1;
		flag = -1;	
	}
	
	for(i = 0; i < size_to_copy; ++i)
	{
		*(char*)dest = *(char*)source;
		*(char**)&dest += flag;
		*(char**)&source += flag;
	}
	return dest;
	
}


