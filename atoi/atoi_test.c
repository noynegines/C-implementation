#include "atoi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void TestAtoi();
void TestItoa();

int main()
{
	TestAtoi();
	TestItoa();
	return 0;
}

void TestItoa()
{
	int count = 0;
	char buffer[20];
	
	if(0 != strcmp(Itoa(456, buffer, 10), "456"))
	{
		++count;
	}
	if(0 != strcmp(Itoa(-789, buffer, 10), "-789"))
	{
		++count;
	}
	if(0 != strcmp(Itoa(123, buffer, 16), "7b"))
	{
		++count;
	}
	printf("failed in %d tests\n", count);
}

void TestAtoi()
{
	int count = 0;
	
	if(Atoi("456", 10) != atoi("456"))
	{ 
		++count;
	}
	if(Atoi("-789", 10) != atoi("-789"))
	{
		++count;
	}
	if(Atoi("10", 12) != atoi("12"))
	{
		++count;
	}
	if(Atoi("1F", 16) != atoi("31"))
	{
		++count;
	}
	printf("failed in %d tests\n", count);
}


