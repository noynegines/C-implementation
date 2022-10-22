#include <stdio.h> /* using printf function */
#include <assert.h> /* using assert function */
#include <ctype.h> /* using tolowr() function */
#include <string.h> /* using all string libaray functions*/
#include <stdlib.h> /* using malloc and free functions */


char *StrCpy(char *dest, const char *src);
char *StrNCpy(char *dest, const char *src, size_t n);
int StrNCmp(const char *s1, const char *s2, size_t n);
int StrCaseCmp(const char *s1, const char *s2);
char *StrChr(const char *s, int c);
char *StrDup(const char *s);
char *StrCat(char *dest, const char *src);
char *StrNCat(char *dest, const char *src, size_t n);
char *StrStr(const char *haystack, const char *needle);
size_t StrSpn(const char *s, const char *accept);
int IsPalindrome(char *s);



int main()
{
	/* question 1: strcpy */
	char str[] = {"abcd"};
	char str2[100];
	/* strncp */
	char str3[] = {"acdjt"};
	char str4[] = "abc";
	int res = 0;
	char str5[] = "ABc";
	char str6[] = "abcg";
	char *ptr = 0;
	char *ptr2 = 0;
	char *ptr3 = 0;
	char *ptr4 = 0;
	char str7[] = "geeksforgeeks";
	char str8[] = "for";
	char str9[] = "noy";
	char str10[] = "noy";
	char str11[] = "abcd";
	char str12[] = "abcg";
	char str13[] = "abcba";
		
	/* question 1: strcpy */
	StrCpy(str2, str);
	printf("strcpy: %s\n", str2);
	
	/* question 1: strncp */
	StrNCpy(str3, str2, 3);
	printf("strncp: %s\n", str3);
	
	/* question 1: strncpy */
	res = StrNCmp(str,str6, 3);
	
    if(res > 0)
    {
        printf("s2 is less than s1\n");
    }
    else if(res < 0)
    {
        printf("s1 is less than s2\n");
    }
    else
    {
        printf("s1 is equal to s2\n");
    }
    
    /* question 1: strcasecmp */
    res = StrCaseCmp(str5, str4);
    if(res > 0)
    {
        printf("s2 is less than s1\n");
    }
    else if(res < 0)
    {
        printf("s1 is less than s2\n");
    }
    else
    {
        printf("s1 is equal to s2\n");
    }
    
    /* question 1: strchr */
    ptr = StrChr(str6,'a');
    /* = strchr(str6, '\0');*/
    printf("strchr: %c\n", (char)*ptr);
    
    /* question 1: strdup */
    ptr2 = StrDup(str6);
    /*ptr2 = strdup(str6);*/
    printf("dup: %s\n", ptr2);
    free(ptr2);
    
    /* questoin 1: strcat */
    /*ptr3 = StrNCat(str,str6,2);*/
    ptr3 = StrCat(str,str6);
    printf("strcat: %s\n", ptr3);
    ptr4 = StrCat(str11, str12);
    printf("strcat2: %s\n", ptr4);
    printf("cmp: %d\n", strcmp(ptr4,ptr3));
    
    /* strstr */
	ptr3 = StrStr(str7, str8);
	/*ptr3 = strstr(str7, str8);*/
	printf("strstr: %s\n", ptr3);
	
	/* strspn */
	/*printf("strspn: %lu\n", StrSpn(str9,str10));*/
	printf("strspn: %lu\n", strspn(str9,str10));
	
	/*palindrome*/
	printf("palindrome: %d\n", IsPalindrome(str13));
	printf("palindrome: %d\n", IsPalindrome(str12));
	
	
	
	
	return 0;
}


char *StrCpy(char *dest, const char *src)
{
	char *start = dest;
	
	assert(NULL != src);
	assert(NULL != dest);
	
	while('\0' != *src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	
	*dest = '\0';
	
	return start;
}


char *StrNCpy(char *dest, const char *src, size_t n)
{
	char *start = dest;
	
	assert(NULL != src);
	assert(NULL != dest);
	
	while('\0' != *src && 0 < n)
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	
	*dest = '\0';
	
	return start;

}

int StrNCmp(const char *s1, const char *s2, size_t n)
{
	assert(NULL != s1);
	assert(NULL != s2);
	
	while((*s1 == *s2 && '\0' != *s1) && 0 < n)
	{
		++s1;
		++s2;
		--n;
	}
	
	return 0 == n ? 0 : *s1-*s2;
}

int StrCaseCmp(const char *s1, const char *s2)
{
	assert(NULL != s1);
	assert(NULL != s2);
	
	while(tolower(*s1) == tolower(*s2) && '\0' != *s1)
	{
		++s1;
		++s2;
	}
	
	return *s1-*s2;

}

char *StrChr(const char *s, int c)
{
	assert(NULL != s);
	
	while('\0' != *s)
	{
		if(*s == c)
		{
			return (char*)s;
		}
		++s;
	}
	return '\0' == c ? (char*)s : NULL;
}

char *StrDup(const char *s)
{
	assert(NULL != s);
	
	size_t len = strlen(s);
	char *dup = (char*)malloc(sizeof(char) * len + 1);
	
	
	if(NULL == dup)
	{
		return (char*)NULL;
	}
	dup = strcpy(dup, s);
	
	return dup;
}

char *StrCat(char *dest, const char *src)
{
	char *ptr = dest + strlen(dest);

	assert(NULL != dest);
	assert(NULL != src);

	
	while('\0' != *src)
	{
		*ptr = *src; 
		++src;
		++ptr;
	}
	
	*ptr = '\0';
	
	return dest;
	
}

char *StrNCat(char *dest, const char *src, size_t n)
{
	char *ptr = dest + strlen(dest);

	assert(NULL != dest);
	assert(NULL != src);

	
	while('\0' != *src && 0 < n)
	{
		*ptr = *src;
		++src;
		++ptr;
		--n;
	}
	
	*ptr ='\0';
	
	return dest;
	
}

char *StrStr(const char *haystack, const char *needle)
{
	int len = strlen(needle);
	
	assert(NULL != haystack);
	assert(NULL != needle);
	
	while( '\0' != *haystack)
	{
		if(0 == StrNCmp(haystack, needle, len))
		{
			return (char*)haystack;
		}
		++haystack;
	}
	
	return NULL;
}

size_t StrSpn(const char *s, const char *accept)
{
	size_t count = 0;

	assert(NULL != s);
	assert(NULL != accept);
	
	while('\0' != *s && NULL != StrChr(accept, (int)*s))
	{
			++count;
			++s;
		
	}
	
	return count;
}


int IsPalindrome(char *start)
{

	char *end = start + strlen(start) - 1;
	
	while(start < end)
	{
		if(*start != *end)
		{
			return 0;
		}
		--end;
		++start;
	}
	return 1;
}
