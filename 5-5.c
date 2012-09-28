#include <stdio.h>

char *strncpy(char *s, char *ct, int n);
char *strncat(char *s, char *ct, int n);
int strncmp(char *cs, char *ct,int n);

int main()
{
	char eka[10] = "asdas";
	char toka[] = "asda";

//	printf("%s\n", strncpy(eka,toka,4));
//	printf("%s\n", strncat(eka,toka,4));
	printf("%i\n", strncmp(eka,toka,4));
	return 0;
}


char *strncpy(char *s, char *ct, int n)
{
	char *tmp = s;

	for (; n && (*s = *ct); *s++, *ct++, n--)
		;
		*s = '\0';
	for (; n > 0; n--)
		*s++ = '\0';
	return tmp;
}

char *strncat(char *s, char *ct, int n)
{
	char *tmp = s;

	for (; *s; *s++)
		;
	for (; n && (*s = *ct); *s++, *ct++, n--);
		;
	for (; n > 0; n--)
		*s++ = '\0';
	return tmp;
}

int strncmp(char *cs, char *ct, int n)
{
	for (; *cs == *ct; *cs++, *ct++) {
		n--;
		if (*cs == '\0' || !n)
			return 0;
	}
	return *cs - *ct;
}
