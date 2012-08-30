#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF){
		while (c == ' '){
			c = getchar();

			if (c != ' ')
				putchar(' ');
		}
		putchar(c);

	}

	return 0;
}
