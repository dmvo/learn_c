#include <stdbool.h>
#include <stdio.h>

void squeeze(char s[], char c[]);

int main()
{
	char s[7] = { 'q', 'w', 'e', 'r', 't', 'y' };
	char c[4] = { 'a', 'q', 'f', 'y' };

	printf("%s\n", s);
	squeeze(s,c);
	printf("%s\n", s);
	return 0;
}

void squeeze(char s[], char c[])
{
	int i, j, n;
	bool exist;

	for (i = j = 0; s[i]; i++) {
		exist = false;
		for (n = 0; c[n]; n++)
			if ((s[i] == c[n]))
				exist = true;
		if (!exist)
			s[j++] = s[i];
	s[j] = '\0';
	}
}
