#include <stdio.h>

int htoi(char s[]);

int main()
{
	printf("%i\n", htoi("0x3c26"));
	return 0;
}

int htoi(char s[])
{
	int i, n, dec;

	i = dec = 0;
	if ((s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	for(; s[i]; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			n = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = s[i] + 10 - 'a';
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = s[i] + 10 - 'A';
		else
			return -1; /* Error */
		dec = 16 * dec + n;
	}
	return dec;
}
