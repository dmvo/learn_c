#include <stdio.h>

void strcat1(char *s, char *t);

int main()
{
	char eka[10] = "moi";
	char toka[] = "kka\n";

	strcat1(eka, toka);
	printf("%s", eka);
	return 0;
}

void strcat1(char *s, char *t)
{
	while (*s)
		*s++;
	while (*s++ = *t++)
		;
}
