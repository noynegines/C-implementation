#include <stdio.h>
#include "stack.h"

int main()
{
	stack_t *stack;
	char ch = '1';
	int i = 0;
	int res = 0;
	void *elem = NULL;
	
	stack = StackCreate(16,sizeof(char));
	printf("stack:\n");
	printf("capacity = %lu \nsize:%lu\n", StackCapacity(stack), StackSize(stack));
	res = StackIsEmpty(stack);
	printf("is empty:%d\n", res);
	StackPush(stack,(void*)(size_t)ch);
	printf("stack after 1 push:\n");
	printf("capacity = %lu \nsize:%lu\n", StackCapacity(stack), StackSize(stack));
	
	for(i = 0; i < 5; ++i)
	{
		StackPush(stack,(void*)(size_t)ch);
	}
	
	printf("stack after 5 push of char:\n");
	printf("capacity = %lu \nsize:%lu\n", StackCapacity(stack), StackSize(stack));
	
	for(i = 0; i < 2; ++i)
	{
		StackPop(stack);
	}
	
	printf("stack after 2 pop of char:\n");
	printf("capacity = %lu \nsize:%lu\n", StackCapacity(stack), StackSize(stack));
	
	res = StackIsEmpty(stack);
	printf("is empty:%d\n", res);
	
	elem = StackPeek(stack);
	printf("peek is:%s \n", (char*)elem);
	printf("capacity = %lu \nsize:%lu\n", StackCapacity(stack), StackSize(stack));
	
	StackDestroy(stack);
	
	
	return 0;
}



