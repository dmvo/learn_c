#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
	printf("%u\n", invert(0xAA, 4, 4));
}

unsigned int invert(unsigned int x, int p, int n)
{

	return x ^ ((~(~0 << n)) << p+1-n);
}
