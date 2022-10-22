#include "atoi.h"
#include <ctype.h> /* isdigit */
#include <assert.h> /* assert */
#include <string.h> /* strlen */

#define BASE_10 (10)
#define OFFSET_0 ('0')
#define NUMS ("0123456789")
#define ASCII_0 (48)
#define ASCII_9 (57)
#define ASCII_A (65)
#define ASCII_Z (90)
#define ASCII_a (97)
#define ASCII_z (122)


static void Reverse(char *head);
static void Swap(char *end, char* start);
static char GetCharFromInt(int num);
static int GetIntFromChar(char str, int base);

char *ItoaBaseTen(int num, char *buffer)
{
	int sign = 1;
	char *head = NULL;
	head = buffer;
	
	assert(NULL != buffer);
	
	if(0 > num)
	{
		sign = -1;
		num = -num;
		*buffer = '-';
		++buffer;
	}
	
	do
	{
		*buffer = NUMS[num % BASE_10];
		++buffer;
		num /= BASE_10;
	}
	while(num != 0);
	
	*buffer = '\0';
	
	if(sign == -1)
	{
		Reverse(head + 1);
	}
	else
	{
		Reverse(head);
	}
	
	return head;
}

int AtoiBaseTen(const char *str)
{
	int res = 0;
	int sign = 1;
	
	assert(NULL != str);
	
	if('-' == *str)
	{
		sign = -1;
		++str;
	}
	
	while(isdigit(*str))
	{
		res *= BASE_10;
		res += *str - OFFSET_0;
		++str;
	}
	
	return res * sign;
	
}

int Atoi(const char *str, size_t base)
{
	int res = 0;
	int sign = 1;
	int digit = 0;

	assert(NULL != str);
	
	if('-' == *str)
	{
		sign = -1;
		++str;
	}
	
	while(-1 != (digit = GetIntFromChar(*str, base)))
	{
		res *= base;
		res += digit;
		++str;
	}
	
	return sign * res;
}
	


static int GetIntFromChar(char str, int base)
{
	int num = -1;
	
	if ((ASCII_0 <= str) && (ASCII_9 >= str) && ((str - ASCII_0) < base))
	{
		num = str - ASCII_0;
	}
	else if ((ASCII_A <= str) && (ASCII_Z >= str) && (((str - ASCII_A) + 10) < base))
	{
		num = str - ASCII_A + 10;
	}
	else if ((ASCII_a <= str) && (ASCII_z >= str) && (((str - ASCII_a) + 10) < base))
	{
		num = str - ASCII_a + 10;
	}
	
	return num;
	
	
}

static char GetCharFromInt(int num)
{
	char res = '\0';
	
	if (num <= 9)
	{
		res = num + ASCII_0;
    }
    else
    {
    	res = num - 10 + ASCII_a;
	}
	
	return res;
}

char *Itoa(int num, char *buffer, size_t base)
{
	int reminder = 0;
	int sign = 1;
	char *head = buffer;
	assert(NULL != buffer);
	
	if(0 > num)
	{
		sign = -1;
		*buffer = '-';
		++buffer;
		num = -num;
	}
	
	while(0 != num)
	{
		reminder = num % base;
		*buffer = GetCharFromInt(reminder);
		++buffer;
		num /= base;
	}
	
	*buffer = '\0';
	
	if(sign == -1)
	{
		Reverse(head + 1);
	}
	else
	{
		Reverse(head);
	}
	
	return head;
}

static void Reverse(char *head)
{
	char *end = NULL;

	assert(NULL != head);
	
	end = head + strlen(head) - 1;
	
	while(end > head)
	{
		Swap(head, end);
		--end;
		++head;
	}
}

static void Swap(char *end, char* start)
{
	char temp = '\0';
	
	assert(NULL != end);
	assert(NULL != start);
	
	temp = *end;
	*end = *start;
	*start = temp;

}
