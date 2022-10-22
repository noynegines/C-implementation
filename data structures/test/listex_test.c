#include <stdio.h>
#include <stdlib.h>

#include "listex.h"

void TestFlip();
void TestLoop();
void TestIntersection();

node_t *init(void *val)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->data = val;
	new_node->next = NULL;
	
	return new_node;
}

int main()
{
	TestFlip();
	TestLoop();
	TestIntersection();
	
	
	return 0;
}

void TestFlip()
{
	int x = 1;
	int y = 2;
	int z = 3;
	node_t *node1 = init((void *)(size_t)x);
	node_t *node2 = init((void *)(size_t)y);
	node_t *node3 = init((void *)(size_t)z);
	
	node1->next = node2;
	node2->next = node3;
	
	printf("%p ",(void *)(node1->data));
	printf("%p ",(void *)(node1->next->data));
	printf("%p ",(void *)(node1->next->next->data));
	
	Flip(node1);
	
	printf("%p ",(void *)(node3->data));
	printf("%p ",(void *)(node3->next->data));
	printf("%p \n",(void *)(node3->next->next->data));
	
	free(node1);
    free(node2);
    free(node3);
}

void TestLoop()
{
	int x = 1;
	int y = 2;
	int z = 3;
	int a = 4;
	int b = 5;
	int c = 6;
	node_t *node1 = init((void *)(size_t)x);
	node_t *node2 = init((void *)(size_t)y);
	node_t *node3 = init((void *)(size_t)z);
	
	node_t *node4 = init((void *)(size_t)a);
	node_t *node5 = init((void *)(size_t)b);
	node_t *node6 = init((void *)(size_t)c);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node1;
	
	printf("has loop? %d - should be 1\n", HasLoop(node1));
	
	node4->next = node5;
	node5->next = node6;
	
	printf("has loop? %d - should be 0\n", HasLoop(node4));
	
	free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

}


void TestIntersection()
{
	int x = 1;
	int y = 2;
	int z = 3;
	int a = 4;
	int b = 5;
	int c = 6;
	int d = 7;
	
	node_t *node1 = init((void *)(size_t)x);
	node_t *node2 = init((void *)(size_t)y);
	node_t *node3 = init((void *)(size_t)z);
	
	node_t *node4 = init((void *)(size_t)a);
	node_t *node5 = init((void *)(size_t)b);
	node_t *node6 = init((void *)(size_t)c);
	node_t *node7 = init((void *)(size_t)d);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node6->next = node4;
	node7->next = node6;
	
	printf("find intersection? %d - should be 1\n",node4 == FindIntersection(node1, node7));

	
	free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
}

