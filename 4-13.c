#include <stdio.h>

void reverse(char s[]);

int main()
{
	char jono[] = "merkkijono";

	printf("%s\n", jono);
	reverse(jono);
	printf("%s\n", jono);

	return 0;
}

void reverse(char s[])
{
        char tmp;
	static int i, j;

	if (!i)
		for (; s[i]; i++)
			;
	if (j < i/2) {
		tmp = s[j];
		s[j] = s[i-j-1];
		s[i-j-1] = tmp;
		j++;
		reverse(s);
	}
}

