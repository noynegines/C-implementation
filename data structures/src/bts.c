#include <stdlib.h> /*allocation*/
#include <assert.h> /*assert*/

#include "bts.h"

typedef enum child_node_pos
{
    LEFT,
    RIGHT,
    NUM_CHILDREN
} child_node_pos_t;

struct bst_node
{
    void *data;
    bst_node_t *parent;
    bst_node_t *children[NUM_CHILDREN];
};

struct bst_struct
{
    bst_node_t *root;
    bst_cmp_t cmp_func;
    void *param;
};



bst_t *BSTCreate(bst_cmp_t cmp_func, void *param)
{
	bst_t *new_bst = NULL;
	bst_node_t *dummy = NULL;
	
	assert(NULL != param);
	
	new_bst = (bst_t *)malloc(sizeof(bst_t));
	if(NULL == new_bst)
	{
		return NULL;
	}
	
	dummy = (bst_node_t *)malloc(sizeof(bst_node_t));
	if(NULL == dummy)
	{
		free(new_bst);
		new_bst = NULL;
		
		return NULL;
	}
	
	dummy->data = 
	
	
}
