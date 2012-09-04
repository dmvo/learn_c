#include <stdio.h>
#define TABSIZE 8

int main()
{
	int c,j,i;

	j = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			i = TABSIZE - (j % TABSIZE);

			for (j = 0; j < i; j++)
				putchar(' ');

			j = 0;
		} else if (c == '\n') {
			putchar(c);
			j = 0;
		} else {
			putchar(c);
			j++;
		}
	}
	return 0;
}
