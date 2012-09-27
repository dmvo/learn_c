#include <stdio.h>

#define swap(t, x, y) {t tmp = x; x = y; y = tmp;}

int main()
{
	int a = 5, b = 6;

	printf("%i, %i\n", a, b);
	swap(int, a, b);
	printf("%i, %i\n", a, b);
	return 0;
}
