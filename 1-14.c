#include <stdio.h>

int main()
{
	int cn[256], c, i, tmp;

	for (i = 0; i < 256; i++)
		cn[i] = 0;

	while ((c = getchar()) != EOF)
		cn[c] = cn[c]++;

	for (i = 0; i < 256; i++) {
		if (cn[i] != 0){
			printf("%c: ", i);
			for (tmp = 0; tmp < cn[i]; tmp++)
				putchar('=');

			putchar('\n');
		}
	}

	return 0;
}
