#include <assert.h> /* assert */
#include <limits.h>
#include "bitArray.h"

#define UNUSED(x) (void)(x)
#define SIZE (CHAR_BIT * sizeof(size_t))
#define MAX (255)
#define NIBBLE (4)
#define MASK_NIBBLE (15)


static size_t lut_set_bits[] =  {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
static size_t SetBitsInEveryByteLut(bit_arr_t arr);

/* ----------------------starting---------------------- */

bit_arr_t BitArrSetAll(bit_arr_t arr)
{
	UNUSED(arr);
	return (bit_arr_t)(-1);
}

bit_arr_t BitArrResetAll(bit_arr_t arr)
{
	UNUSED(arr);
	return (bit_arr_t)(0);
}

bit_arr_t BitArrSetOn(bit_arr_t arr, size_t index)
{
	size_t mask = 1;
	
	assert(SIZE > index);
	
	mask = mask << index;
	
	return arr | mask;
}

bit_arr_t BitArrSetOff(bit_arr_t arr, size_t index)
{
	size_t mask = 1;
	
	assert(SIZE > index);
	
	mask = mask << index;
	mask  = ~mask;
	
	return arr & mask;
}

bitArr_bit_val_t BitArrGetBitVal(bit_arr_t arr, size_t index)
{
	size_t mask = 1;
	mask = mask << index;
	
	if(mask == (arr & mask))
	{
		return ON;
	}
	
	return OFF;
}

bit_arr_t BitArrSetBitVal(bit_arr_t arr, size_t index, bitArr_bit_val_t bit_val)
{	
	if(0 == bit_val)
	{	
		return BitArrSetOff(arr, index);
	}

	
	return BitArrSetOn(arr, index);
}

size_t BitArrCountSetBits(bit_arr_t arr)
{
	size_t count = 0;
	
	while (0 != arr)
	{
		arr = arr & (arr - 1);
		++count;
	}
	
	return count;
}

size_t BitArrCountOffBits(bit_arr_t arr)
{		
	return SIZE - BitArrCountSetBits(arr);
			
}

bit_arr_t BitArrRotateL(bit_arr_t arr, size_t num_of_rotations)
{
	return (arr << num_of_rotations)|(arr >> (SIZE - num_of_rotations));
	
}

bit_arr_t BitArrRotateR(bit_arr_t arr, size_t num_of_rotations)
{
	return (arr >> num_of_rotations)|(arr << (SIZE - num_of_rotations));
}

bit_arr_t BitArrMirror(bit_arr_t arr)
{
	arr = ((arr & 0xFFFFFFFF00000000) >> 32) | ((arr & 0x00000000FFFFFFFF) << 32);
  	arr = ((arr & 0xFFFF0000FFFF0000) >> 16) | ((arr & 0x0000FFFF0000FFFF) << 16);
  	arr = ((arr & 0xFF00FF00FF00FF00) >> 8)  | ((arr & 0x00FF00FF00FF00FF) << 8);
  	arr = ((arr & 0xF0F0F0F0F0F0F0F0) >> 4)  | ((arr & 0x0F0F0F0F0F0F0F0F) << 4);
  	arr = ((arr & 0xCCCCCCCCCCCCCCCC) >> 2)  | ((arr & 0x3333333333333333) << 2);
  	arr = ((arr & 0xAAAAAAAAAAAAAAAA) >> 1)  | ((arr & 0x5555555555555555) << 1);
  	
  	return arr;
}

bit_arr_t BitArrFlipBit(bit_arr_t arr, size_t index)
{
	size_t mask = 1;
	
	assert(SIZE > index);
	
	mask = mask << index;
	
	return mask ^ arr;
	
}

char *BitArrConvertToString(bit_arr_t arr, char *dest)
{
	size_t i = 0;
	size_t mask = 1;
	char *head = dest;
	
	assert(NULL != dest);
	
	mask = mask << (SIZE - 1);
	
	for(i = 0; i < SIZE; ++i)
	{
		*dest = ((0 == (arr & mask))? '0' : '1');
		++dest;
		mask = mask >> 1;

	}
	
	*dest = '\0';
	
	return head;
}


static size_t SetBitsInEveryByteLut(bit_arr_t arr)
{
	size_t bits_on = 0;
	size_t i = 0;
	
	for(i = 0; i < 16; ++i)
	{
		bits_on += lut_set_bits[arr & MASK_NIBBLE];
		arr = arr >> NIBBLE;
	}
	
	return bits_on;
}


