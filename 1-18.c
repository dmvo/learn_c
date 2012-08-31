#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int lim);
void filter(char s[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline1(line, MAXLINE)) > 0) {
		filter(line, len);
		printf("%s", line);
	}
	return 0;
}

int getline1(char s[], int lim)
{
        int c, i;

        for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

void filter(char s[], int len)
{
	while ((s[len-2] == ' ' || s[len-2] == '\t') && len > 0)
		--len;
	s[len-1] = '\n';
	s[len] = '\0';
}
