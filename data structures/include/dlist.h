#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h> /* size_t */
#include "cstmdef.h"

typedef struct node_struct dlist_node_t;
typedef struct dlist_struct dlist_t;


typedef int (*is_match_t)(const void *data_list, const void *data_param);
typedef int (*dlist_action_t)(void *data, void *param);

typedef enum ret_val dlist_ret_val_t;

typedef struct dlist_iter
{
    dlist_node_t *node;
}dlist_iter_t;
/*
    Description: 
    	function that creates an empty doubly-linked list.
    params: none
    return:
        pointer to the created list.
        error: returns NULL.
    complexity:
    time - O(1).
    space - O(1).
*/
dlist_t *DListCreate(void);


/*
    Description: 
    	function that deletes a doubly-linked list.
    params:
        list - pointer to a valid doubly-linked list.
    return:
       void.
    complexity:
    time - O(n).
    space - O(1).
*/
void DListDestroy(dlist_t *list);


/*
    Description: 
    	function that deletes specified element. 
    params:
       iterator - handle to a valid element. 
    return:
      returns an iterator to the next element after the removed.
    complexity:
    time - O(1).
    space - O(1).
*/

dlist_iter_t DListRemove(dlist_iter_t iterator);


/*
    Description: 
    	function that deletes first element of the dlist and returns it.
    	trying to pop an empty list will result in undefined behaviour
    params:
       list - valid pointer to a doubly-linked list.
    return:
      pointer to the element.
    complexity:
    time - O(1).
    space - O(1).
*/

void *DListPopFront(dlist_t *list);


/*
    Description: 
    	function that deletes last element of the dlist and return it. 
    	trying to pop an empty list will result in undefined behaviour
    params:
        list - valid pointer to linked list.
    return:
        pointer to the element.
    complexity:
        time - O(1).
        space - O(1).
*/
void *DListPopBack(dlist_t *list);

/*
    Description: 
    	function that inserts a element with element's data to specific place
    	in a dlist.
    params:
        iterator - valid pointer to specific element.
        data - data of an element in the list. 
    return:
        On success: return the iterator to the element that was inserted.
        if fails- returns an iterator to the end of the list
    complexity:
    time - O(1).
    space - O(1).
*/
dlist_iter_t DListInsertBefore(dlist_t *list, dlist_iter_t where, const void *data);


/*
    Description: 
    	function that inserts an element into the end of the list
    params:
        list - valid pointer to a linked list.
        data - the element to be inserted.
    return:
        On success: an iterator to the data that has been pushed
        On failure: an iterator to the end of the list
    complexity:
    time - O(1).
    space - O(1).
*/
 dlist_iter_t DListPushBack(dlist_t *list, const void *data);
 

 /*
    Description: 
    	function that inserts an element to the beginning of the given dlist
    params:
        list - valid pointer to linked list.
        data - the element to be inserted
    return:
        On success: an iterator to the data that has been pushed
        On failure: an iterator to the end of the list
    complexity:
    time - O(1).
    space - O(1).
*/
 dlist_iter_t DListPushFront(dlist_t *list, const void *data);


/*
    Description: 
    	function that gets the data of specific element in the dlist.
    params:
        iterator - handle to a valid element.
        if passed an invalid iterator will result in undefined behaviour
    return: 
    	The data of the specific element.
        
    complexity:
    time - O(1).
    space - O(1).
*/
void *DListGetData(dlist_iter_t iterator);


/*
    Description: 
    	function that sets the data of specific element in the dlist, must be a valid iterator.
    params:
        iterator - handle to a valid element.
        data - the data that needs to be set
    return:pointer to the element.
        none.
    complexity:
        time - O(1).
        space - O(1).
*/
void DListSetData(dlist_iter_t iterator, const void *data);


/*
    Description: 
    	returns the number of elements in the specified list
    params: 
        list - valid pointer to doubly-linked list.
    return:
        the amount of elements in the doubly-list
    complexity:
        time - O(n).
        space - O(1).
*/      
size_t DListSize(const dlist_t *list);


/*
    Description: 
    	The function checks if a given dlist is empty
    params: 
        list - valid pointer to an object of type dlist_t
    return:
        1 - if the list is empty, 0 if not
    complexity:
        time - O(1).
        space - O(1).
*/
int DListIsEmpty(const dlist_t *list);

/*
    Description: 
    	function that looks for specific data in the dlist.
    params:
        list - valid pointer to linked dlist.
        data - data of an element in the dlist.
        compare_function_t - a pointer to a function that compares 2 values and returns the comparision status - if 1 - is match, else 0.
    return:
        iterator - pointer to an element that was found (equal to data).
        if not found - returns to.
    complexity:
        time - O(n).
        space - O(1).
*/
dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to, const void *data, is_match_t match_function);


/*
    Description: 
    	This function finds all nodes in a given list that
    	match the given parameter and puts them in a list.
    params: 
        from - valid iterator from which to start looking
        to - valid iterator until which to look 
        param - the variable that will be matched against the element using the match_function parameter
        match_function - a pointer to a function that compares 2 values and returns the comparision status - if 1 - is match, else 0.
        dest_list - an output paramater, a list that will contain the found nodes.
    return:
        amount of elements that matched in the range [from, to).
    complexity:
        time - O(n).
        space - O(n).
*/
size_t DListMultiFind(dlist_iter_t from, dlist_iter_t to, void *param, is_match_t match_function, dlist_t *dest_list);


/*
    Description: 
    	returns the begining of the list.
    params: 
        list - valid pointer to a linked list.
    return:
        pointer to the begining of the link list
    complexity:
        time - O(1).
        space - O(1).
*/
dlist_iter_t DListBegin(const dlist_t *list);


/*
    Description: 
    	returns the last valid element of the list.
    params:
        list - valid pointer to a linked list.
    return:
        iterator to the end of the list
    complexity:
        time - O(1).
        space - O(1).
*/
dlist_iter_t DListEnd(const dlist_t *list);


/*
    Description: 
    	function that checks if two given iterators are equal.
    params: 
        iterator1 - valid pointer to specific element
        iterator2 - valid pointer to specific element
    return:
        returns status -SUCCESS/FAILURE.
    complexity:
        time - O(1).
        space - O(1).
*/
dlist_ret_val_t DListIsIterEqual(dlist_iter_t iterator1, dlist_iter_t iterator2);


/*
    Description: 
    	function that gets an dlist_iter_t and return dlist_iter_t that points 
    	to the next element.
    params: 
        iterator - valid pointer to specified element
    return:
        iterator - handle to a valid element.
        if iterator is end of list - returns iterator.
    complexity:
        time - O(1).
        space - O(1).
*/
dlist_iter_t DListIterNext(dlist_iter_t iterator);


/*
    Description: 
    	function that gets an dlist_iter_t and return previous dlist_iter_t .
    params: 
        iterator - valid pointer to specific element
    return:
        iterator - handle to a valid element.
        if iterator is the first element of the list - returns iterator.
    complexity:
        time - O(1).
        space - O(1).
*/
dlist_iter_t DListIterPrev(dlist_iter_t iterator);

/*
    Description: 
    	The function does operation specified by action pointer on element 
    	in the range [itaerator, itaerator + number_of_elements).
    params: 
         iterator - handle to a valid element.
         action_function - valid pointer to function that acts on the data of the elements.
         param - an output parameter that can be used by the function caller in conjunction with the passed action_function_t
    return:
        SUCCESS/FAILURE of the operation.
    complexity:
        time - O(n).
        space - O(1).
*/
dlist_ret_val_t DListForEach(dlist_iter_t from, dlist_iter_t to,
						dlist_action_t action_function, void *param);

/*
    Description:
        This function adds a portion (or the entirety) of one dlist into
        a specified location in a list
    params: 
        where - valid iterator of destination of the splice
        from - valid terator from where to splice
        to - valid iterator to where to splice
    return:
        iterator - handle to the last element that was added.
    complexity:
        time - O(1).
        space - O(1).
*/
dlist_iter_t DListSplice(dlist_iter_t where, dlist_iter_t from, dlist_iter_t to);


#endif   /* __DLIST_H__  */


