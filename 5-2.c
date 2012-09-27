#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

float getch(void);
void ungetch(float);
int getfloat(float *pn);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
	float c = 5.0;

	getfloat(&c);
	printf("%f\n", c);

	return 0;
}

int getfloat(float *pn)
{
	int sign;
	float c, power;

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
		if (c == '.') {
			c = getch();
			for (power = 1.0; isdigit(c); c = getch()) {
				*pn = 10 * *pn + (c - '0');
				power *= 10.0;
			}
			*pn = *pn / power;
		}
		*pn *= sign;
	} else {
		ungetch(c);
		return 0;
	}
	if (c != EOF)
		ungetch(c);
	return c;
}

float getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(float c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
