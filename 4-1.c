#include <stdio.h>
#define MAXLINE 1000

int strrindex(char s[], char t[]);
int getline1(char s[], int lim);

char pattern [] = "asd";

int main()
{
	char line[MAXLINE];
	int found, test;

	found = test = 0;
	while (getline1(line, MAXLINE) > 0)
		if ((test = strrindex(line, pattern)) >= 0) {
			printf("%i  %s",test, line);
			found++;
		}
	return found;
}

int strrindex(char s[], char t[])
{
	int i, j, k, tmp;

	for (i = 0, tmp = 0; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; j++, k++)
			;
		if ( k > 0 && !t[k])
			tmp = i;
	}
	if(tmp)
		return tmp;
	return -1;
}

int getline1(char s[], int lim)
{
	int c, i;

	for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

