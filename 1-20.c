#include <stdio.h>
#define TABSIZE 8

int main()
{
	int c,j,i;

	j = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			i = TABSIZE - (j % TABSIZE);
			j = 0;
			while  (j < i) {
				putchar(' ');
				j++;
			}
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
