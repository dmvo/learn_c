#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[10];

	itob(255, s, 16);
	printf("%s\n", s);
	itob(255, s, 2);
	printf("%s\n", s);
	return 0;
}

void itob(int n, char s[], int b)
{
	int i, tmp, sign;

	sign = (n < 0) ? -1 : 1;
	i = 0;
	do {
		s[i++] = ((tmp = sign * (n % b)) < 10) ? tmp + '0' : tmp -10 + 'A';
	} while (n /= b);
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
