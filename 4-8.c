#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define VARIABLE 'a'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print_stack_top(void);
void duplicate_stack_top(void);
void swap_top(void);
void clear(void);
char var_or_func(char txt[]);
void vpush(char x);
char vpop(void);

int sp = 0;
double val[MAXVAL];
char buf = EOF;
int bufp = 0;
double var[26];
char vbuf[26];
int vsp = 0;
void ungets(char s[]);

void vpush(char x)
{
	vbuf[vsp++] = x;
}

char vpop(void)
{
	return vbuf[--vsp];
}

int main()
{
	int type;
	double op2;
	char tmp;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case VARIABLE:
			push(var[s[0] - 'a']);
			vpush(s[0]);
			break;
		case '=':
			tmp = vpop();
			duplicate_stack_top();
			var[tmp - 'a'] = pop();
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case 'S':
			push(sin(pop()));
			break;
		case 'E':
			push(exp(pop()));
			break;
		case 'P':
			op2 = pop();
			push(pow(pop(),op2));
			break;
		case '?':
			print_stack_top();
			break;
		case '~':
			swap_top();
			break;
		case '#':
			duplicate_stack_top();
			break;
		case '@':
			clear();
			break;
		case '\n':
			var['z' - 'a'] = pop();
			printf("\t%.8g\n", var['z' - 'a']);
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void print_stack_top(void)
{
	if (sp > 0)
		printf("%f\n", val[sp-1]);
	else
		printf("error: stack empty\n");
}
void duplicate_stack_top(void)
{
	double tmp;

	tmp = pop();
	push(tmp);
	push(tmp);
}
void swap_top(void)
{
	double first, second;

	first = pop();
	second = pop();
	push(first);
	push(second);
}

void clear(void)
{
	for(; sp > 0; sp--)
		val[sp] = '\0';
	val[sp] = '\0';
}

int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
		return c;
	i = 0;

	while (isalpha(c) && i < 2) {
		s[i++] = c;
		c = getch();
	}
	if (i > 0)
		return var_or_func(s);

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '-')
		if (isdigit(s[++i] = c = getch()))
			while (isdigit(s[++i] = c = getch()))
			;
		else
			return '-';
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
char var_or_func(char txt[])
{
	if (txt[0] == 's' && txt[1] == 'i' && txt[2] == 'n')
		return 'S';
	else if (txt[0] == 'e' && txt[1] == 'x' && txt[2] == 'p')
		return 'E';
	else if (txt[0] == 'p' && txt[1] == 'o' && txt[2] == 'w')
		return 'P';
	else
		return VARIABLE;
}

int getch(void)
{
	int tmp;

	if (buf != EOF) {
		tmp = buf;
		buf = EOF;
		return tmp;
	} else {
		return getchar();
	}
}

void ungetch(int c)
{
	if (buf != EOF)
		printf("ungetch: too many characters\n");
	else
		buf = c;
}

void ungets(char s[])
{
	int i;

	for (i = 0; s[i]; i++)
		ungetch(s[i]);
}
