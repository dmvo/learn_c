#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main()
{
	printf("%u\n", rightrot(0x80000001, 4));
	return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
	for (; n > 0; n--)
		x = (x >> 1) | ((x & ~(~0 << 1)) << 31);
	return x;
}
