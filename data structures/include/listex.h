#ifndef __LISTEX_H__
#define __LISTEX_H__

typedef struct node
{
	void *data;
	struct node *next;
} node_t;

node_t *Flip(node_t *head);
int HasLoop(const node_t *head);
node_t *FindIntersection(node_t *head1, node_t *head2);




#endif /* __LISTEX_H__ */
