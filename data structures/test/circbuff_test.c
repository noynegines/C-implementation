#include <stdio.h>

#include "circbuff.h"

void TestIsEmptyAndSize();
void TestReadWrite();

int main()
{
	
	TestIsEmptyAndSize();
	TestReadWrite();

	return 0;
}

void TestIsEmptyAndSize()
{
	circBuff_t *buffer1 = NULL;
	circBuff_t *buffer2 = NULL;
	size_t failure = 0;
	int x = 5;
	char a = 'a';
	
	printf("*****************************\n");
	printf("testing is empty and size:\n");
	printf("*****************************\n");
	
	buffer1 = CircBuffCreate(5);
	if(CircBuffIsEmpty(buffer1) != 1)
	{
		printf("Test line 39 failed\n");
		++failure;
	}
	
	if(CircBuffSiz(buffer1) != 0)
	{
		printf("Test line 47 failed\n");
		++failure;
	}
	
	buffer2 = CircBuffCreate(20);
	CircBuffWrite(buffer2, (void*)&x,4);
	if(CircBuffIsEmpty(buffer2) != 0)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	if(CircBuffSiz(buffer2) != 4)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	CircBuffWrite(buffer2, (void *)&a, 1);
	if(CircBuffIsEmpty(buffer2) != 0)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	if(CircBuffSiz(buffer2) != 5)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	CircBuffRead(buffer2, &a, 1);
	if(CircBuffIsEmpty(buffer2) != 0)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	if(CircBuffSiz(buffer2) != 4)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	printf("Test is empty: %s with %lu failures \n", (failure > 0) ? "failed" : "succes", failure);
	
	CircBuffDestroy(buffer1);
	CircBuffDestroy(buffer2);
}

void TestReadWrite()
{
	circBuff_t *buffer1 = NULL;
	circBuff_t *buffer2 = NULL;
	
	int y = 10;
	char a = 'a';
	short c = 2, d =4;
	size_t failure = 0;
	
	printf("\n\n\n*****************************\n");
	printf("testing read and write:\n");
	printf("*****************************\n");
	
	buffer1 = CircBuffCreate(2);	
	buffer2 = CircBuffCreate(5);
	
	CircBuffRead(buffer1, &a, 1);
	if(CircBuffRead(buffer1, &a, 1) != -1)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	CircBuffWrite(buffer1, (void *)&c, 2);
	if(CircBuffSiz(buffer1) != 2)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(CircBuffFreeSpace(buffer1) != 0)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	
	if(CircBuffFreeSpace(buffer2) != 5)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	if(CircBuffWrite(buffer1, (void *)&a, 1) != 1)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	CircBuffWrite(buffer2, (void *)&y, 4);
	if(CircBuffSiz(buffer2) != 4)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(CircBuffFreeSpace(buffer2) != 1)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	CircBuffWrite(buffer2, (void *)&c, 4);
	if(CircBuffSiz(buffer2) != 5)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(CircBuffFreeSpace(buffer2) != 0)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	CircBuffRead(buffer2, &a, 1);
	if(CircBuffSiz(buffer2) != 4)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(CircBuffFreeSpace(buffer2) != 1)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	
	CircBuffRead(buffer2, &d, 4);
	if(CircBuffSiz(buffer2) != 0)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(CircBuffFreeSpace(buffer2) != 5)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(CircBuffIsEmpty(buffer2) != 1)
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	
	
	printf("Test read and write: %s with %lu failures \n", (failure > 0) ? "failed" : "succes", failure);
	
	CircBuffDestroy(buffer1);
	CircBuffDestroy(buffer2);
	
}

