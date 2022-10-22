#include <stdio.h>
#include "bitArray.h"

int main()
{
	char buffer[100];
	bit_arr_t arr = {0};
	bit_arr_t arr2 = 6;
	bit_arr_t arr3 = 6;
	bit_arr_t rot = 4;
	bit_arr_t rot2 = 4;
	bit_arr_t mirror = 1500; /* 10111011100 */
	bit_arr_t flip = 5;
	bit_arr_t num = 7;
	size_t count = 0;
	bit_arr_t new = 7;
	

	arr = BitArrSetAll(arr);
	printf("Set All: %s\n", BitArrConvertToString(arr, buffer));
	
	arr = BitArrResetAll(arr);
	printf("Reset All: %s\n", BitArrConvertToString(arr, buffer));
	
	arr = BitArrSetOn(arr, 2);
	printf("Set On Index 2: %s\n", BitArrConvertToString(arr, buffer));
	
	arr = BitArrSetOff(arr, 2);
	printf("Set Off Index 2: %s\n", BitArrConvertToString(arr, buffer));
	
	printf("val of index 1 of 6: %d\n", BitArrGetBitVal(arr2, 1));
	printf("val of index 0 of 6: %d\n", BitArrGetBitVal(arr2, 0));
	
	arr3 = BitArrSetBitVal(arr3, 2, 0);
	printf("6 after set index 2 -> 0: %s\n", BitArrConvertToString(arr3, buffer));
	
	count = BitArrCountSetBits(new);
	printf("Count Set Bits: %lu\n", count);
	
	count = BitArrCountOffBits(new);
	printf("Count off Bits: %lu\n", count);
	
	rot = BitArrRotateL(rot, 1);
	printf("4 after rotate left 1: %s\n", BitArrConvertToString(rot, buffer));
	
	rot2 = BitArrRotateR(rot2, 2);
	printf("4 after rotate right 2: %s\n", BitArrConvertToString(rot2, buffer));
	
	printf("before mirror: %s\n", BitArrConvertToString(mirror, buffer));
	mirror = BitArrMirror(mirror);
	printf("after mirror: %s\n", BitArrConvertToString(mirror, buffer));
	
	flip = BitArrFlipBit(flip, 2);
	printf("flip num 5 index 2: %s\n", BitArrConvertToString(flip, buffer));


	return 0;
	
}


