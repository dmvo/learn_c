#include <stdio.h>

int main()
{
	int c;

	printf("type characters, EOF quits\n");

	while (((c = getchar()) != EOF) != 0) {
		printf("%i\n", (c != EOF));
	}

	printf("got an EOF: %i\n", (c != EOF));

	return 0;
}
