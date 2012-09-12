#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char s[12];

	itoa(INT_MIN,s);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;

	sign = (n < 0) ? -1 : 1;
	i = 0;
	do {
		s[i++] = sign * (n % 10) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	char tmp;
	int i, j;

	for (i = 0; s[i]; i++)
		;

	for (j = 0; j < i/2; j++) {
		tmp = s[j];
		s[j] = s[i-j-1];
		s[i-j-1] = tmp;
	}
}
