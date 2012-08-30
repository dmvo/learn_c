#include <stdio.h>

int main(void)
{
	/* Will create warning because there is no \c escape sequence*/
	printf("hello, world\c");
	return 0;
}
