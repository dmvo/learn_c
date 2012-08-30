#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("Celsius Fahrenheit\n");

	while (celsius <= upper){
		fahr =  celsius * 1.8 + 32.0;
		printf("%3.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
