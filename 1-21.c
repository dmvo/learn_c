#include <stdio.h>
#define MAXLINE 1000
#define TABSIZE 8

int getline1(char s[], int lim);

int main()
{
	char line[MAXLINE];
	int len, i, j, n, blanks, tabs, p;

	blanks = 0;
	while ((len = getline1(line, MAXLINE)) > 0) {
		for (i = 0; i < len; i++) {
			if (line[i] == ' ')
				blanks++;
			else {
				n = i - blanks;
				if ((blanks > 1) && (blanks >= (TABSIZE - (n % TABSIZE)))) {
					line[n] = '\t';
					blanks = blanks - (TABSIZE - ( n % TABSIZE));
					n++;
					tabs = blanks / TABSIZE;
					for (p = 0; p < tabs; p++, n++) {
						line[n] = '\t';
						blanks = blanks - TABSIZE;
					}
					for (p = 0; p < blanks; p++, n++)
						line[n] = ' ';
					blanks = 0;
					j = i - n;
					for (n = n; line[n+j] != '\0';n++)
						line[n] = line[n+j];
					line[n] = '\0';
				} else {
					blanks = 0;
				}
			}
		}
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

