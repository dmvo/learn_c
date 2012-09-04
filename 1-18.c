#include <stdbool.h>
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
	int i;
	bool flag = false;

	if (s[len-1] == '\n') {
		flag = true;
		len--;
	}

	for (i = len-1; (i >= 0) && (s[i] == ' ' || s[i] == '\t'); i--)
		;
	if (flag) {
		s[i+1] = '\n';
		s[i+2] = '\0';
	} else {
		s[i+1] = '\0';
	}
	if (s[0] == '\n')
		s[0] = '\0';
}
