#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h> /* size_t */

typedef struct node_struct slist_node_t;

typedef struct slist_struct slist_t;
typedef slist_node_t *slist_iter_t;
typedef int(*match_function_t)(const void *data_list, void *data_param);
typedef int (*operation_function_t)(void *data, void *param);

/* Move the implementations to the *c file */


typedef enum slist_ret_val
{
    SUCCESS = 0,
    FAILURE = 1
} slist_ret_val_t;

/*
    Description: function that creates a new singly linked list.
    return:
        pointer to the new list struct.
        error: returns NULL.
    complexity:
    time - O(1).
    space - O(n).
*/
slist_t *SListCreate(void);

/*
    Description: function that deletes a linked list.
    params:
        list - pointer to linked list.
    return:
       
    complexity:
    time - O(n).
    space - O(1).
*/
void SListDestroy(slist_t *list);


/*
    Description: function that inserts a element with element's data to specific place in the list.
    params:
        iterator - pointer to specific element.
        data - data of an element in the list. 
    return:
        return the iterator to the element that was inserted.
    complexity:
    time - O(1).
    space - O(1).
*/
 slist_iter_t SListInsertBefore(slist_iter_t where, const void *data);


/*
    Description: function that deletes specific element. 
    params:
       iterator - pointer to specific element. 
    return:
      returns the next iterator after the deleted element.
    complexity:
    time - O(1).
    space - O(1).
*/
slist_iter_t SListRemove(slist_iter_t iterator);


/*
    Description: function that looks for specific data in the list.
    params:
        list - pointer to linked list.
        data - data of an element in the list.
        compare_function_t - a pointer to a function that compares 2 values and returns the comparision status.
    return:
        iterator - pointer to an element that was found (equal to data).
    complexity:
    time - O(n).
    space - O(1).
*/
slist_iter_t SListFind(slist_iter_t from, slist_iter_t to, const void *data, match_function_t match_function);


/*
    Description: function that gets the data of specific element in the list
    params:
        iterator - pointer to specific element that we look for its data.
    return: The data of the specific element.
       
    complexity:
    time - O(1).
    space - O(1).
*/
void *SListGetData(slist_iter_t iterator);


/*
    Description: function that sets the data of specific element in the list
    params:
        iterator - pointer to specific element that we look for its data.
        val - the data that needs to be set
    return:
        pointer to specific element that was set.
       
    complexity:
    time - O(1).
    space - O(1).
*/
void SListSetData(slist_iter_t iterator, const void *data);



/*
    Description: returns the head of the list.
    params: 
        list - pointer to linked list.
    return:
        pointer to the head of the link list
    complexity:
    time - O(1).
    space - O(1).
*/
slist_iter_t SListBegin(const slist_t *list);


/*
    Description: returns the tail of the list.
    params:
        list - pointer to linked list.
    return:
        iterator to the end of the list
    complexity:
    time - O(1).
    space - O(1).
*/
slist_iter_t SListEnd(const slist_t *list);


/*
    Description: returns the size of a linked list
    params: 
        list - pointer to linked list.
    return:
        the amount of elements in the list
    complexity:
    time - O(n).
    space - O(1).
*/      
size_t SListCount(const slist_t *list);

/*
    Description: function that checks if two given iterators are equal.
    params: 
        iterator1 - pointer to specific element
        iterator2 - pointer to specific element
    return:
        returns status -SUCCESS/FAILURE.
    complexity:
        time - O(1).
        space - O(1).
*/
slist_ret_val_t SListIsIterEqual(slist_iter_t iterator1, slist_iter_t iterator2);

/*
    Description: function that gets an slist_iter_t and return slist_iter_t that points to the next element.
    params: 
        iterator - pointer to specific element
    return:
        iterator - pointer to the next element
    complexity:
        time - O(1).
        space - O(1).
*/
slist_iter_t SListIterNext(slist_iter_t iterator);


/*
    Description: The function does operation specified by operation pointer on element in the range [itaerator, itaerator + number_of_elements).
    params: 
         iterator - pointer to specific element
         number_of_element - the amount of elements to be changed
         operation_function - pointer to function that does an operation on the data of the elelemnts.
    return:
        SUCCESS/FAILURE of the operation.
    complexity:
        time - O(n).
        space - O(1).
*/

slist_ret_val_t SListForEach(slist_iter_t from, slist_iter_t to, operation_function_t operation_function, void *param);

/*
    Description: The function checks if a given list is empty
    params: 
        list - pointer to an object of type slist_t
    return:
        1 - if the list is empty, 0 if not
    complexity:
        time - O(1).
        space - O(1).
*/
int SListIsEmpty(const slist_t *list);

/* go to slist.h
    Description: function that appends src list to dest.
    params:
        dest - a pointer to list. cant be NULL
        src - a pointer to list that will be append to dest. after append src will stay valid. cant be NULL
    return:
        result - a pointer to dest.
    complexity:
    time - O(1).
    space - O(1).
*/

slist_t *SListAppend(slist_t *dest, slist_t *src);


#endif  /* __SLIST_H__ */

