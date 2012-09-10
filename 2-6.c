#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main()
{
	printf("%u\n", setbits(0xaa, 4, 4, 0xaa));
	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n));
}
