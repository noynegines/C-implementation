#ifndef __CIRCBUFF_H__
#define __CIRCBUFF_H__

#include <stddef.h> /* size_t */

/* to be moved to *.c */

typedef struct circBuff circBuff_t;


/*
    Description: function that creates a new circular buffer instance
    params: 
        capacity - the size of the circular buffer in bytes
    return:
        pointer to the new circular buffer struct.
        On error returns NULL.
    complexity:
    time - O(1).
    space - O(n).
*/
circBuff_t *CircBuffCreate(size_t capacity);

/*
    Description: function that deletes a given circular buffer.
    params: 
        circular buffer - pointer to circular buffer.
    return:
        none
    complexity:
    time - O(1).
    space - O(1).
*/
void CircBuffDestroy(circBuff_t *buff);

/*
    Description: 
        function that writes n_bytes from src to buff
    parameters:
        buff - a valid pointer to circBuff_t instance
        src - pointer to the source to copy into buff
        n_bytes - the amount of bytes to write 
    return:
        the amount of bytes that written 
        on error = -1
    complexity:
        time O(1)
        space O(1)
*/
int CircBuffWrite(circBuff_t *buff, const void *src, size_t n_bytes);

/*
    Description: 
        
    parameters:
        buff - a valid pointer to circBuff_t instance
        dest - pointer to the dest to copy data from buff
        n_bytes - the amount of bytes to read
    return:
        the amount of bytes that read
        on error = -1
    complexity:
        time O(1)
        space O(1)
*/
int CircBuffRead(circBuff_t *buff, void *dest, size_t n_bytes);

/*
    Description: 
        function checks if the buffer is empty.
    parameters:
        buff - a valid pointer to circBuff_t instance
    return:
        1 if empty.
        0 if not empty.
    complexity:
    time - O(1)
    space - O(1)
*/
int CircBuffIsEmpty(const circBuff_t *buff);

/*
    Description: function that returns the number of used bytes 
                in the circular buffer. 
    params: 
        buff - a pointer of circular buffer
    return:
        the number of used bytes in the circular buffer
        
    complexity:
    time - O(1).
    space - O(1).
*/
size_t CircBuffSiz(const circBuff_t *buff);

/*
    Description: function that returns the number of free bytes 
                in the circular buffer. 
    params: 
        buff - a pointer of circular buffer
    return:
        the number of free bytes in the circular buffer
        
    complexity:
    time - O(1).
    space - O(1).
*/
size_t CircBuffFreeSpace(const circBuff_t *buff);


#endif /* __CIRCBUFF_H__  */
