#include <stdio.h>
#define MAXLINE 1000
#define WIDTH 80

int getline1(char s[], int lim);

int main()
{
	int last_blank, len, i, j;
	char line[MAXLINE];

	last_blank = 0;
	while ((len = getline1(line, MAXLINE)) > 0) {
		if (len > WIDTH) {
			for (i = 0, j = 0; i < len; i++, j++) {
				if (line[i] == ' ' || line[i] == '\t')
					last_blank = i;
				if (j > 80 && last_blank != 0) {
					line[last_blank] = '\n';
					last_blank = 0;
					j = 0;
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

