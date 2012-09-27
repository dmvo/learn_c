#include <stdio.h>

void itoa(int n, char s[]);
int main()
{
	int number = -12346;
	char s[5];

	itoa(number, s);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[])
{
	static int i, sign;

	if (!sign)
		if ((sign = n) < 0)
			n = -n;
	if ((n / 10) > 0)
		itoa(n/10, s);
	else if (sign < 0)
		s[i++] = '-';
	s[i++] = n % 10 + '0';
	s[i] = '\0';
}
