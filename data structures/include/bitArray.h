#ifndef __BITARRAY_H__
#define __BITARRAY_H__

#include <stddef.h> /* Used for size_t */

typedef size_t bit_arr_t;

typedef enum bitArr_bit_val
{
    OFF = 0,
    ON = 1
} bitArr_bit_val_t;

/*
Description:
These functions Set/Reset all the bits in the array (set all bits to 0 or 1).
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
return:
	returns a new instance of arr with the modified values.
complexity:
    time - O(n).
    space - O(n).
*/
bit_arr_t BitArrSetAll(bit_arr_t arr);
bit_arr_t BitArrResetAll(bit_arr_t arr);

/*
Description:
These functions Set/Reset the arr[index] bit.
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
	index - the index of the bit that will be set\reset.
return:
	returns a new instance of arr with the modified values.
complexity:
    time - O(1).
    space - O(n).
*/
bit_arr_t BitArrSetOn(bit_arr_t arr, size_t index);
bit_arr_t BitArrSetOff(bit_arr_t arr, size_t index);

/*
Description:
This function gets specific bit's value.
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
	index - the index of the bit.
return:
	returns the value of the bit, either OFF->0 or ON->1.
complexity:
    time - O(1).
    space - O(1).
*/
bitArr_bit_val_t BitArrGetBitVal(bit_arr_t arr, size_t index);

/*
Description:
This function sets a specific bit's value.
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
	index - the index of the bit.
	bit_val - the value to set (either OFF->0 or ON->1).
return:
	returns a new instance of arr with the modified values.
complexity:
    time - O(1).
    space - O(n).
*/
bit_arr_t BitArrSetBitVal(bit_arr_t arr, size_t index, bitArr_bit_val_t bit_val);

/*
Description:
These functions count on/off bits.
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
return:
	returns the amount of the set on/off bits.
complexity:
    time - O(n).
        Amortized - O(log(n)).
    space - O(1).
*/
size_t BitArrCountSetBits(bit_arr_t arr);
size_t BitArrCountOffBits(bit_arr_t arr);

/*
Description:
These functions rotate the array left or right by a number of rotations.
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
return:
	returns a new instance of arr with the modified values.
complexity:
    time - O(n).
    space - O(n).
*/
bit_arr_t BitArrRotateL(bit_arr_t arr, size_t num_of_rotations);
bit_arr_t BitArrRotateR(bit_arr_t arr, size_t num_of_rotations);

/*
Description:
This function mirrors the entire bit array. Ex: 1101 -> 1011
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
return:
	returns a new instance of arr with the modified values.
complexity:
    time - O(log(n)).
    space - O(n).
*/
bit_arr_t BitArrMirror(bit_arr_t arr);

/*
Description:
This function flips the value of a specific bit. 
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
return:
	returns a new instance of arr with the modified values.
complexity:
    time - O(1).
    space - O(n).
*/
bit_arr_t BitArrFlipBit(bit_arr_t arr, size_t index);

/*
Description:
This function copies the array to a string9.
params:
	arr - An array of bit values (0 / 1). Can't be NULL.
	str - A string to contain the bit array as string.
return:
	returns pointer to the start of the bit array string. returns NULL on failure.
complexity:
    time - O(n).
    space - O(n).
*/
char *BitArrConvertToString(bit_arr_t arr, char *dest);

#endif /* __BITARRAY_H__ */
