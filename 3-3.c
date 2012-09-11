#include <stdio.h>
#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main()
{
	char s1[MAXLINE] = "-d-j A-G0-9 numerot: 2-9 0-4 -a-z";
	char s2[MAXLINE];

	expand(s1,s2);
	printf("%s\n", s1);
	printf("%s\n", s2);
	return 0;
}

void expand(char s1[], char s2[])
{
	char salphabets[] = "abcdefghijklmnopqrstuvwxyz";
	char balphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numbers [] = "0123456789";
	int i, j, tmp;

	for (i = 0, j = 0; s1[i]; i++)
		if (s1[i] == '-' && i > 0) {
			if ((s1[i-1] >= 'a') && (s1[i-1] <= 'z'))
				for (tmp = (s1[i-1] - 'a') + 1; salphabets[tmp] != s1[i+1]; tmp++, j++)
					s2[j] = salphabets[tmp];
			else if ((s1[i-1] >= 'A') && (s1[i-1] <= 'Z'))
				for (tmp = (s1[i-1] - 'A') + 1; balphabets[tmp] != s1[i+1]; tmp++, j++)
					s2[j] = balphabets[tmp];
			else if ((s1[i-1] >= '0') && (s1[i-1] <= '9'))
				for (tmp = (s1[i-1] - '0') + 1; numbers[tmp] < s1[i+1]; tmp++, j++)
					s2[j] = numbers[tmp];
		} else {
			s2[j++] = s1[i];
		}
	s2[j] = '\0';
}
