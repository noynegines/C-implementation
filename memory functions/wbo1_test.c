#include <stdio.h>
#include "wbo1.h"

int main()
{
  	char src[] = "hello world";
    char dest[] = "my name is noy azut";
    char try[] = "abcd";
	char str[] = "finaly i finish it!";
	char try1[] ="ghjjcdef";

    
    Memset(str,'$',7);
    printf("%s\n", str);
    Memcpy(dest,src, 3);
    printf("%s\n", dest);
    Memmove(try1 ,try , 3);
    printf("%s\n", try1);

	return 1;
}
