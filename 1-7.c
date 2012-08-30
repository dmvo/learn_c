#include <stdio.h>

int main(){

	int c;

	while ((c = getchar()) != EOF);
	printf("%i\n", c); /* print value of EOF */

	return 0;
}
