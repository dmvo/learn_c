#include <stdio.h>

int strend(char *s, char *t);

int main()
{
	char eka[] = "lolasdlol";
	char toka[] = "lol";

	printf("%i\n", strend(eka, toka));

	return 0;
}

int strend(char *s, char *t)
{
	char *tmp = t;

	while (*s) {
		while (*s++ == *t) {
			*t++;
			if (!*s && !*t)
				return 1;
		}
		t = tmp;
	}
	return 0;
}
