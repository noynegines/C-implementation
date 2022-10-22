/*
Dev - Noy
Reviewer- Paz 
Subject - SList exercise
date - 05/09/2022 
*/


#include <stddef.h> /* size_t */
#include <assert.h> /* assert */

#include "listex.h"

node_t *Flip(node_t *head)
{
	node_t *current = head;
	node_t *next_node = NULL;
	node_t *prev_node = NULL;
	
	assert(NULL != head);
	
	while(NULL != current)
	{
		next_node = current->next;
		current->next = prev_node;
		prev_node = current;
		current = next_node;
	}
	
	head = prev_node;
	return head;
}

int HasLoop(const node_t *head)
{
	node_t *ptr1 = NULL;
	node_t *ptr2 = NULL;
	
	assert(NULL != head);
	
	ptr1 = (node_t *)head;
	ptr2 = (node_t *)head;
	
	while(NULL != (ptr2->next) && NULL != (ptr2->next->next))
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		
		if(ptr1 == ptr2)
		{
			return 1;
		}
	}
	return 0;
}

static size_t GetLen(node_t *node)
{
	size_t count = 0;
	
	assert(NULL != node);
	
	while(NULL != node)
	{
		++count;
		node = node->next;
	}
	return count;
}

node_t *FindIntersection(node_t *head1, node_t *head2)
{
	size_t len1 = 0;
	size_t len2 = 0;
	size_t diff = 0;
	
	assert(NULL != head1);
	assert(NULL != head2);
	
	len1 = GetLen(head1);
	len2 = GetLen(head2);
	
	if(len1 < len2)
	{
		diff = len2 -len1;
		
		while(0 < diff)
		{
			head2 = head2->next;
			--diff;
		}
	}
	else
	{
		diff = len1 - len2;
		
		while(0 < diff)
		{
			head1 = head1->next;
			--diff;
		}
	}
	
	while(head2 != head1)
	{
		head1 = head1->next;
		head2 = head2->next;
		
		if(head1 == head2)
		{
			return head1;
		}
	}
	
	return NULL;
}
