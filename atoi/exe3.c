#include <stdio.h>


#define IS_LIITLE_ENDIAN (1 == ((char)*(char*)&"1") ? 1:0)

int IsLiitleEndian(int data);

int main()
{
	int data = 1;
	int res = 0;
	res = IsLiitleEndian(data);
	
	if(res ==1)
	{
		printf("little endian\n");
	}
	else
	{
		printf("big endian\n");
	}

	return 0;
}

int IsLiitleEndian(int data)
{
	char *c = (char*)&data;

	return (*c == 1)? 1:0;
}
