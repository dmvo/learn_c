#include <stdio.h>

int main()
{
	/* Will create warning because there is no \c escape sequence */
	printf("hello, world\c");
	return 0;
}
