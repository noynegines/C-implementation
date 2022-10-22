/*
Dev - Noy
Reviewer- Idan 
date -
*/

#include <assert.h> /* assert*/
#include <stdlib.h> /* malloc free */

#include "circbuff.h"


struct circBuff
{
    size_t read_index;
    size_t write_index;
    size_t capacity;
    char data[1];
};

circBuff_t *CircBuffCreate(size_t capacity)
{
	circBuff_t *buffer = (circBuff_t *)malloc(offsetof(circBuff_t, data) + capacity);
	if(NULL == buffer)
	{
		return NULL;
	}
	
	buffer->read_index = 0;
	buffer->write_index = 0;
	buffer->capacity = capacity;
	
	return buffer;
}

void CircBuffDestroy(circBuff_t *buff)
{
	assert(NULL != buff);

	free(buff);
	buff = NULL;
}

int CircBuffWrite(circBuff_t *buff, const void *src, size_t n_bytes)
{
	size_t count = 0;
	
	assert(NULL != buff);
	assert(NULL != src);
	
	if(n_bytes > buff->capacity)
	{
		return -1;
	}
	
	
	while(0 < n_bytes)
	{
		buff->data[(buff->write_index) % (buff->capacity)] = *(char *)src;
		--n_bytes;
		++(*(char **)&src);
		++count;
		
		if(buff->write_index == buff->read_index + buff->capacity)
		{
			++(buff->read_index);
		}
		++buff->write_index;
	}
	return count;
}

int CircBuffRead(circBuff_t *buff, void *dest, size_t n_bytes)
{
	size_t count = 0;
	assert(NULL != buff);
	assert(NULL != dest);
	
	if(n_bytes > CircBuffSiz(buff))
	{
		return -1;
	}
	
	while(0 < n_bytes)
	{
		*(char *)dest = buff->data[buff->read_index % buff->capacity];
		--n_bytes;
		++*(char **)&dest;
		++buff->read_index;
		++count;	
	}
	
	return count;
}

int CircBuffIsEmpty(const circBuff_t *buff)
{
	return buff->read_index == buff->write_index;
}

size_t CircBuffSiz(const circBuff_t *buff)
{
	size_t size = 0;
	
	if(buff->write_index - buff->read_index > buff->capacity)
	{
		size = buff->capacity;
	}
	else
	{
		size = buff->write_index - buff->read_index;
	}
	return size;
}

size_t CircBuffFreeSpace(const circBuff_t *buff)
{
	return buff->capacity - CircBuffSiz(buff);
}

