#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
	printf("%i\n", bitcount(0xAA));
	return 0;
}
/*	from the book.
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
*/
int bitcount(unsigned int x)
{
	int b;

	for (b = 0; x != 0; x &= (x-1))
		b++;

	return b;
}
