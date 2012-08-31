#include <stdio.h>

float convert(float fahr);

int main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Fahrenheit Celsius\n");

	while (fahr <= upper) {
		printf("%3.0f %12.1f\n", fahr, convert(fahr));
		fahr = fahr + step;
	}

	return 0;
}

float convert(float fahr)
{
	float celsius;
	celsius = (5.0/9.0) * (fahr-32.0);

	return celsius;
}
