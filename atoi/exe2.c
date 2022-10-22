#include <stdio.h>
#include <stdlib.h>

#define ASCII_SIZE (128)
#define DONT_PRINT_CHAR (1)
#define NULL_TERMINATOR ('\0')
#define PRINT_CHAR (2)


void PrintCommonLetters(const char *arr1, const char *arr2, const char *arr3)
{
	size_t letters[128] = {0};
	size_t i = 0;
	
	while('\0' != *arr1)
	{
		letters[(size_t)*arr1] = 1;
		++arr1;
	}
	
	while('\0' != *arr2)
	{
		if(letters[(size_t)*arr2] == 1)
		{
			letters[(size_t)*arr2] = 2;
		}
		else if(letters[(size_t)*arr2] == 0)
		{
			letters[(size_t)*arr2] = 1;
		}
		++arr2;
	}
	
	while('\0' != *arr3)
	{
		if(letters[(size_t)*arr3] == 2)
		{
			letters[(size_t)*arr3] = 1;
		}
		else
		{
			letters[(size_t)*arr3] = 1;
		}
		++arr3;
	}
	
	for(i = 0; i < 128; ++i)
	{
		if(letters[i] == 2)
		{
			printf("%c ", (char)i);
		}
	}
}

int main()
{
	PrintCommonLetters("abbbccdddef","1234abc8","2a");
	return 0;
}


