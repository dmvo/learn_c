#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *pn);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
	int c = 5;

	getint(&c);
	printf("%i\n", c);

	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (isdigit(c)) {
		for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');
		*pn *= sign;
	} else {
		ungetch(c);
		return 0;
	}
	if (c != EOF)
		ungetch(c);
	return c;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
