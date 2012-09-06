#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int lim);

int main()
{
	int len, i, start, stop, j, k;
	char line[MAXLINE];

	start = stop = -1;
	while ((len = getline1(line, MAXLINE)) > 0) {
		for (i = 0; i < len-3; i++) {
			if (line[i] == '/')
				if (line[i+1] == '*')
					start = i;
			if (start != -1)
				if (line[i+2] == '*')
					if (line[i+3] == '/')
						stop = i+3;
			if (start != -1 && stop != -1) {
				for (j = start, k = 1; j < len; j++, k++)
					line[j] = line[stop+k];
				len = len - (stop - start);
				line[len] = '\0';
				start = stop = -1;
			}
		}
		printf("%s\n", line);
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

