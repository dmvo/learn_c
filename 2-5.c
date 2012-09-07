#include <stdbool.h>
#include <stdio.h>

int any(char s[], char c[]);

int main()
{
	char s[7] = { 'q', 'w', 'e', 'r', 't', 'y' };
	char c[5] = { 'a', 'b', 'f', 't' };

	printf("s: %s\n", s);
	printf("c: %s\n", c);
	printf("%i\n", any(s,c));
	return 0;
}

int any(char s[], char c[])
{
	int i, j, n;
	bool exist;

	for (i = j = 0; s[i]; i++) {
		exist = false;
		for (n = 0; c[n]; n++)
			if ((s[i] == c[n]))
				exist = true;
		if (exist)
			return i;
	}
	return -1;
}
