#include <stdio.h>

#define MAX 255

long Pow2(unsigned int base, unsigned int exponent);
void TestPow2();

int IsPowOfTwo(unsigned int num);
void TestIsPowOfTwo();

int IsPowOfTwoLoop(unsigned int num);
void TestIsPowOfTwoLoop();

void PrintThreeBitsOn(unsigned int *array, size_t size);

int IsTwoAndSixBitsOn(unsigned char ch);
void TestIsTwoAndSixBitsOn();

int IsTwoOrSixBitsOn(unsigned char ch);
void TestIsOrAndSixBitsOn();

unsigned char SwapBitsThreeAndFive(unsigned char ch);

void SwapWithoutBitwise(int *num1, int *num2);
void TestSwapWithoutBitwise();

unsigned int CountSetBitsLoop(int num);
void TestCountSetBitsLoop();

int IncrementByOne(int num);
void TestIncrementByOne();

unsigned char ByteMirrorLoop(unsigned char num);
void TestByteMirrorLoop();

unsigned int ClosestModuloSixteen(unsigned int num);
void TestClosestModuloSixteen();

void PrintBitsOfFloat(float num);
unsigned char ByteMirror(unsigned char num);
void InitLutMirror();


unsigned int CountSetBits(int num);
void InitLut();
int lut_set_bits[256];
int lut_mirror[256];


int main()
{
	
	
	InitLut();
	InitLutMirror();
	TestPow2();
	TestCountSetBitsLoop();
	TestIsPowOfTwoLoop();
	TestIsPowOfTwo();
	TestIsTwoAndSixBitsOn();
	TestIsOrAndSixBitsOn();
	TestSwapWithoutBitwise();
	TestIncrementByOne();
	TestByteMirrorLoop();
	TestClosestModuloSixteen();
	
	
	
	
	return 0;
}

long Pow2(unsigned int base, unsigned int exponent)
{
	return base << exponent;
}

void TestPow2()
{	printf("*********************************************************\n\n");
	printf("test for Pow2:\n\n");	
	printf("%u * (2 ^ %u) = %ld\n", 2, 4, Pow2(2,4));
	printf("%u * (2 ^ %u) = %ld\n", 2, 3, Pow2(2,3));
}



unsigned int CountSetBitsLoop(int num)
{
	unsigned int mask = 1;
	unsigned int count = 0;
		
	while(0 != mask)
	{
		if(1 <= (num & mask))
		{
			++count;
		}
		mask = mask << 1;
	}
	
	return count;
}

void TestCountSetBitsLoop()
{	
	printf("*********************************************************\n\n");
	printf("test for CountSetBitsLoop:\n\n");	
	printf("%d = %u\n", 4, CountSetBitsLoop(4));
	printf("%d = %u\n", 7, CountSetBitsLoop(7));
}

int IsPowOfTwoLoop(unsigned int num)
{
	size_t bits_on = CountSetBitsLoop(num);

	if(1 == bits_on)
	{
		return 1;
	}
	
	return 0;
}

void TestIsPowOfTwoLoop()
{	
	printf("*********************************************************\n\n");
	printf("test for IsPowOfTwoLoop:\n\n");	
	printf("%u = %d\n", 4, IsPowOfTwoLoop(4));
	printf("%u = %d\n", 7, IsPowOfTwoLoop(7));
}


int IsPowerOfTwo(unsigned int num)
{
	unsigned int condition = num&(num - 1);
	unsigned int condition2 = num != 0;
	
	
	return (condition == 0 && condition2);
}

void TestIsPowOfTwo()
{	
	printf("*********************************************************\n\n");
	printf("test for IsPowOfTwo:\n\n");	
	printf("%u = %d\n", 4, IsPowOfTwoLoop(4));
	printf("%u = %d\n", 7, IsPowOfTwoLoop(7));
}


void PrintThreeBitsOn(unsigned int *array, size_t size)
{
	size_t i = 0;
	size_t bits_on = 0;
	
	for(i = 0; size > i; ++i)
	{
		bits_on = CountSetBitsLoop(array[i]);
		if(3 == bits_on)
		{
			printf("%u\n", array[i]);
		}
	}
}


int IsTwoAndSixBitsOn(unsigned char ch)
{
	int condition2 = (ch &(1<<1)) >> 1;
	int condition6 = (ch &(1<<5)) >> 5;
	
	return condition2 & condition6;
}

void TestIsTwoAndSixBitsOn()
{	
	printf("*********************************************************\n\n");
	printf("test for IsTwoAndSixBitsOn:\n\n");	
	printf("%s\n", (IsTwoAndSixBitsOn('a') == 0) ? "test passed" : "test failed");
	printf("%s\n", (IsTwoAndSixBitsOn('?') == 1) ? "test passed" : "test failed");
}

int IsTwoOrSixBitsOn(unsigned char ch)
{
	int condition2 = (ch &(1<<1)) >> 1;
	int condition6 = (ch &(1<<5)) >> 5;
	
	return (condition2 | condition6);		
}

void TestIsOrAndSixBitsOn()
{	
	printf("*********************************************************\n\n");
	printf("test for IsOrAndSixBitsOn:\n\n");	
	printf("%s\n", (IsTwoAndSixBitsOn('a') == 1) ? "test passed" : "test failed");
	printf("%s\n", (IsTwoAndSixBitsOn('?') == 1) ? "test passed" : "test failed");
}

void SwapWithoutBitwise(int *num1, int *num2)
{
	
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}

void TestSwapWithoutBitwise()
{	
	int x = 5;
	int y = 7;
	printf("*********************************************************\n\n");
	printf("test for SwapWithoutBitwise:\n\n");	
	

	printf("before: x is: %d, y is: %d\n", x, y);
	SwapWithoutBitwise(&x, &y);
	printf("after: x is: %d, y is: %d\n", x, y);

}

int IncrementByOne(int num)
{
	int mask = 1;
	int carry = 0;
	
	while(0 != mask)
	{
		carry = num & mask;
		num = num ^ mask;
		mask = carry << 1;
	}
	
	return num;
}

void TestIncrementByOne()
{	
	int x = 5;
	printf("*********************************************************\n\n");
	printf("test for IncrementByOne:\n\n");	
	

	printf("before: x is: %d\n", x);
	printf("after: x is: %d\n", IncrementByOne(x));

}

unsigned char ByteMirrorLoop(unsigned char num)
{
	unsigned char mirror = 0;	
	
	while(0 < num)
	{
		mirror = mirror << 1;
		
		if(1 == (num & 1))
		{
			mirror = mirror ^ 1;
		}
		
		num = num >> 1;
	}
	
	return mirror;
}

void TestByteMirrorLoop()
{	
	printf("*********************************************************\n\n");
	printf("test for ByteMirrorLoop:\n\n");	
	
	printf("%s\n",(ByteMirrorLoop(0) == 0) ? "test passed" : "test Failed");
	printf("%s\n",(ByteMirrorLoop(84) == 21) ? "test passed" : "test Failed");

}


unsigned int ClosestModuloSixteen(unsigned int num)
{
	unsigned int mask = ~15;
	
	return num & mask;
}

void TestClosestModuloSixteen()
{	
	printf("*********************************************************\n\n");
	printf("test for ClosestModuloSixteen:\n\n");	
	
	printf("%s\n",(ClosestModuloSixteen(22) == 16) ? "test passed" : "test Failed");
	printf("%s\n",(ClosestModuloSixteen(17) == 16) ? "test passed" : "test Failed");

}

unsigned char SwapBitsThreeAndFive(unsigned char ch)
{
	unsigned int bit3 = (ch >> 2 & 1); /*move to the right*/
	unsigned int bit5 = (ch >> 4 & 1); /*move to the right*/
	unsigned int res = 0;
	
	res = (bit3 ^ bit5);
	res = (res << 2) | (res << 4); /* put the xor back to the original place */
	res = ch ^ res;
	
	return res;
}

void PrintBitsOfFloat(float num)
{
	unsigned int x = (unsigned int)num;
	int count = 31;
	int bit_print = 0;
	
	for(count = 31; count >= 0; --count)
	{
		bit_print = (x >> count) & 1;
		printf("%u", bit_print);
	}
	printf("\n");
}


void InitLut()
{
	int i = 0;
	lut_set_bits[0] = 0;
	for(i = 1; 256 > i; ++i)
	{
		lut_set_bits[i] = (i & 1) + lut_set_bits[i / 2];
	}
}

unsigned int CountSetBits(int num)
{
	unsigned int bits_on = lut_set_bits[num & MAX];
	
	num = num >> 8;
	bits_on += lut_set_bits[num & MAX];
	num = num >> 8;
	bits_on += lut_set_bits[num & MAX];
	num = num >> 8;
	bits_on += lut_set_bits[num & MAX];
	
	return bits_on;
}



void InitLutMirror()
{
	size_t i = 0;
	for (i = 0; 256 > i; ++i)
	{
		lut_mirror[i] = ByteMirrorLoop((unsigned char)i);
	}
}


unsigned char ByteMirror(unsigned char num)
{
	return lut_mirror[(unsigned int)num];
}
