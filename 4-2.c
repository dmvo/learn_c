#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main()
{
	printf("%f\n", atof("123.45e-2"));
	return 0;
}

double atof(char s[])
{
	double val, power, value;
	int i, sign, exp, m;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	value = sign * val / power;
	if ((s[i] == 'e') || (s[i] == 'E')) {
		i++;
		exp = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			i++;
		for (m = 0; isdigit(s[i]); i++)
			m = 10.0 * m + (s[i] - '0');
		if (exp == -1)
			for (i = 0; i < m; i++)
				value = value * (1/10.0);
		else
			for (i = 0; i < m; i++)
				value = value * 10;
	}
	return value;
}
