#include <stdio.h>

int main(void)
{
	printf("hello, world\c"); //Will create warning because there is no \c escape sequence
	return 0;
}
