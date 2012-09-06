#include <limits.h>
#include <stdio.h>

int main()
{
	printf("unsigned char:\t\t%u\t\t%u\n", 0, UCHAR_MAX);
	printf("Signed char:\t\t\%i\t\t%i\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned short int:\t%u\t\t%u\n", 0, USHRT_MAX);
	printf("Signed short int:\t%i\t\t%i\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned int:\t\t%u\t\t%u\n", 0, UINT_MAX);
	printf("Signed int: \t\t%i\t%i\n", INT_MIN, INT_MAX);
	printf("Unsigned long int: \t%lu\t\t%lu\n", 0, ULONG_MAX);
	printf("Signed long int: \t%li\t%li\n", LONG_MIN, LONG_MAX);
return 0;
}
