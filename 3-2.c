#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
void escape_to_char(char s[], char t[]);

int main()
{
	char t[MAXLINE] = "merkki\tjono\n";
	char s[MAXLINE];

	escape(s, t);
	printf("%s", t);
	printf("%s\n", s);
	escape_to_char(t, s);
	printf("%s", t);
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;

	for (i = 0, j = 0; t[i]; i++)
		switch(t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];
			break;
		}

	s[j] = '\0';
}

void escape_to_char(char s[], char t[])
{
	int i, j;

	for (i = 0, j = 0; t[i]; i++)
		switch(t[i]) {
		case '\\':
			switch(t[i+1]) {
			case 't':
				s[j++] = '\t';
				i += 2;
				break;
			case 'n':
				s[j++] = '\n';
				i += 2;
				break;
			}
		default:
			s[j++] = t[i];
			break;
		}
	s[j] = '\0';
}
