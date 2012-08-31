#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int lim);
void reverse(char s[]);

int main()
{
        int len;
        char line[MAXLINE];

        while ((len = getline1(line, MAXLINE)) > 0) {
                reverse(line);
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

void reverse(char s[])
{
	char tmp[MAXLINE];
	int i,j;

	i = 0;
	while (s[i] != '\n')
		i++;
	j = i - 1;
	for (i = 0; i <= j; i++)
		tmp[i] = s[j-i];

	for (i = 0; i <= j; i++)
		s[i] = tmp[i];
}
