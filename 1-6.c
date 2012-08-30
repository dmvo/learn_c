#include <stdio.h>

int main(void){

	int c;

	printf("type characters, EOF quits \n");

	while (c){
		c = getchar() != EOF;
		printf("%i\n", c); /* if 0 == EOF, if 1 != EOF */
	}
	return 0;
}
