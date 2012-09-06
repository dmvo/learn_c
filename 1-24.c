#include <stdbool.h>
#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int lim);

int main()
{
	int len, i, parentheses, brackets, braces;
	bool comment, squot, dquot;
	char line[MAXLINE];

	comment = dquot = squot = false;
	parentheses = brackets = braces = 0;
	while ((len = getline1(line, MAXLINE)) > 0) {
		for (i = 0; i < len; i++) {
			if ((line[i] ==  '/') && (line[i+1] == '*') && !comment)
				comment = true;
			else if ((line[i] == '*') && (line[i+1] == '/') && comment)
				comment = false;
			else if ((line[i] == '(') && !comment)
				parentheses++;
			else if ((line[i] == ')') && !comment)
				parentheses--;
			else if ((line[i] == '[') && !comment)
				brackets++;
			else if ((line[i] == ']') && !comment)
				brackets--;
			else if ((line[i] == '{') && !comment)
				braces++;
			else if ((line[i] == '}') && !comment)
				braces--;
			else if ((line[i] == '\'') && !comment)
				squot = !squot;
			else if ((line[i] == '"') && !comment)
				dquot = !dquot;
		}
	}
	if (parentheses != 0)
        	printf("Parenthesis missing\n");
	if (brackets != 0)
		printf("Bracket missing\n");
	if (braces != 0)
		printf("Brace missing\n");
	if (dquot == true)
		printf("double quote missing\n");
	if (squot == true)
		printf("single quote missing\n");
	if (comment == true)
		printf("file ends inside comment\n");
	return 0;

}

int getline1(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	 return i;
}

