#ifndef __SORTEDLIST_H__
#define __SORTEDLIST_H__

#include <stddef.h> /* size_t */
#include "cstmdef.h"
#include "dlist.h" /* included for sort_list_ter_t full definition*/

typedef struct sorted_list_struct sorted_list_t;
typedef struct sorted_list_iter_struct sorted_list_iter_t;
typedef int (*sorted_list_match_t)(const void *data, const void *param);
typedef int (*compare_t)(const void *lhs, const void *rhs);
typedef int (*sorted_list_action_t)(void *data, void *param);
typedef enum ret_val sorted_list_ret_val_t;

struct sorted_list_iter_struct
{
    dlist_iter_t dlist_iter;
    #ifndef NDEBUG
        sorted_list_t *list;
    #endif
};

/*typedef enum sorted_list_ret_val
{
    SUCCESS = 0,
    FAILURE = 1
} sorted_list_ret_val_t;*/


/*
    Description: 
    	function that creates an empty Sorted list .
    params: 
        cmp_func - comparison function to determine the order of the elements.
    return:
        pointer to the created list.
        error: returns NULL.
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_t *SortedListCreate(compare_t cmp_func);


/*
    Description: 
    	function destroys and cleans up a given sorted list.
    params:
        list - valid pointer to a sorted list.
    return:
       void.
    complexity:
        time - O(n).
        space - O(1).
*/
void SortedListDestroy(sorted_list_t *list);


/*
    Description: 
    	function that inserts an element to the Sorted list
        specified by pointer list.
    params:
        list - valid pointer to Sorted list.
        data - data to be inserted. 
    return:
        On success: an iter object to inserted data
        In case of failure returns iter object to the end of list (terminator)
    complexity:
        time - O(n).
        space - O(1).
*/
sorted_list_iter_t SortedListInsert(sorted_list_t *list, const void *data);


/*
    Description: 
    	function removes an element specified by iter. 
    params:
        iterator - handler to a valid element. 
    return:
        returns an iterator to the next element after the removed.
        on error returns the end of list.
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iter);


/*
    Description: 
    	function searches an element with value data in Sorted list
    	pointed by list and returns an iterator to the element.
    params:
        from - valid iterator from where to search
        to - valid iterator up to where to search
        list - valid pointer to Sorted list.
        data - data to be found. 
    return:
        On success: an iter object to the element
        In case of not finding element with required data, returns "iter to"
    complexity:
        time - O(n).
        space - O(1).
*/
sorted_list_iter_t SortedListFind(sorted_list_iter_t from, sorted_list_iter_t to, const void *data, sorted_list_t *list);


/*
    Description: 
    	function searches an element with value data in Sorted list pointed by list and returns an iterator to the element.
    params:
        from - valid iterator from where to search
        to - valid iterator up to where to search
        data - data to be found.
        is_match - a matching function to determine if the an element matches.
    return:
        On success: an iter object to the element
        In case of not finding element with required data, returns "iter to"
    complexity:
        time - O(n).
        space - O(1).
*/
sorted_list_iter_t SortedListFindCustom(sorted_list_iter_t from, sorted_list_iter_t to, const void *data, sorted_list_match_t *is_match);


/*
    Description: 
    	function that gets the data of specific element in the Sorted list.
    params:
        iterator - handler to a valid element.
        passing an invalid iterator will result in undefined behaviour
    return: 
    	The data of the specific element.
        
    complexity:
    time - O(1).
    space - O(1).
*/
void *SortedListGetData(sorted_list_iter_t iterator);


/*
    Description: 
    	returns the an iterator to the begining of the list.
    params: 
        Sorted list - valid pointer to a sorted list.
    return:
        a handle to the beginning of the sorted list
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_iter_t SortedListBegin(const sorted_list_t *list);


/*
    Description: 
    	returns the end of the list.
    params:
        list - valid pointer to a sorted list.
    return:
        iterator to the end of the list
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_iter_t SortedListEnd(const sorted_list_t *list);


/*
    Description: 
    	function that gets an iterator and return iterator that points 
    	to the next element in ascending order.
    params: 
        
    return:
        iterator - handle to a valid element.
        if iterator is end of list - returns iterator that was sent.
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_iter_t SortedListIterNext(sorted_list_iter_t iterator);


/*
    Description: 
    	function that gets an iterator and return previous iterator
    	to previous element.
    params: 
        iterator - valid pointer to specific element
    return:
        iterator - handle to a valid element.
        if iterator is the first element of the list - returns iterator that was sent.
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_iter_t SortedListIterPrev(sorted_list_iter_t iterator);


/*
    Description: 
    	The function checks if a given list is empty
    params: 
        list - valid pointer to an object of type sorted_list_t
    return:
        1 - if the list is empty
        0 - if not
    complexity:
        time - O(1).
        space - O(1).
*/
int SortedListIsEmpty(const sorted_list_t *list);


/*
    Description: 
    	function that checks if two given iterators are equal.
    params: 
        lhs - handle to a valid specified element.
        rhs - handle to a valid specified element.
    return:
        returns status -SUCCESS/FAILURE.
    complexity:
        time - O(1).
        space - O(1).
*/
sorted_list_ret_val_t SortedListIsIterEqual(sorted_list_iter_t lhs, sorted_list_iter_t rhs);


/*
    Description: 
    	The function does operation specified by action pointer on element 
    	in the range [itaerator, itaerator + number_of_elements).
    params: 
         iterator(iterator from and iterator to) - handle to a valid element.
         action_function - valid pointer to function that acts on the data of the elements .
         param - an output parameter that can be used by the function caller in conjunction with the passed action_function_t
    return:
        SUCCESS/FAILURE of the operation.
    complexity:
        time - O(n).
        space - O(1).
*/
sorted_list_ret_val_t SortedListForEach(sorted_list_iter_t from, sorted_list_iter_t to, sorted_list_action_t action_function, void *param);


/*
    Description: 
    	function that deletes first element of the sorted list and returns it.
    	trying to pop an empty list will result in undefined behaviour
    params:
       list - valid pointer to a sorted list.
    return:
      pointer to the element.
    complexity:
        time - O(1).
        space - O(1).
*/
void *SortedListPopFront(sorted_list_t *list);


/*
    Description:  
    	function that deletes last element of the sorted list and returns it. 
    	trying to pop an empty list will result in undefined behaviour
    params:
        list - valid pointer to sorted list.
    return:
        pointer to the element.
    complexity:
        time - O(1).
        space - O(1).
*/
void *SortedListPopBack(sorted_list_t *list);

/*
    Description: 
    	function that provides merged sorted list from dest list and src list. 
    	the merging algoritm uses the compare function of the dest list. 
    params: 
        dest - valid pointer to sorted list to absorb the src list
        src - valid pointer to sorted list to be merged into dest
    return:
        iterator to the begining of the dest list.
    complexity:
        time - O(n).
        space - O(1).
*/
void SortedListMerge(sorted_list_t *dest, sorted_list_t *src);

size_t SortedListSize(const sorted_list_t *list);

#endif   /* __SORTEDLIST_H__  */


