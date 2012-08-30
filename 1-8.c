#include <stdio.h>

int main(void)
{
	int c, nl, blanks, tabs;

	nl = blanks = tabs = 0;

	while ((c = getchar()) != EOF){
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++tabs;
		else if (c == ' ')
			++blanks;
	}

	printf("%i %i %i\n", blanks, tabs, nl);
	return 0;
}
