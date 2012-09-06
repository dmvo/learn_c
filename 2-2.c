#include <stdbool.h>
#include <stdio.h>

int main()
{
	int i, lim, c;
	char s[10];
	bool stop;

	printf("for loop with &&\n");

	lim = 10;
	for (i = 0; i < lim -1 && (c = getchar()) != '\n' && c != EOF; i++)
		s[i] = c;

	printf("for loop without &&\n");

	for (i = 0; i < lim - 1; i++) {
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break;
		s[i] = c;
	}

	printf("for loop without && and break\n");

	stop = false;
	i = 0;
	while(!stop) {
		stop = !stop;
		if (i < lim -1)
			if ((c = getchar()) != '\n')
				if (c != EOF) {
					s[i] = c;
					i++;
					stop = !stop;
				}
	}

	return 0;
}
