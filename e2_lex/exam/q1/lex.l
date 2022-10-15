%{
#include <stdio.h>
int copy(char *);
int flag = 0, a, b, op;
%}
%%
[0-9]+ { copy(yytext); }
[+\-*/] { op = yytext[0]; }
(.|\n) { ; }
%%

int copy(char *yytext) {
	int n;
	sscanf(yytext, "%d", &n);
	if(flag == 0) {
		a = n;
		flag = 1;
	}
	else {
		int res;
		b = n;
		switch(op) {
			case '+': res = a + b; break;
			case '-': res = a - b; break;
			case '*': res = a * b; break;
			case '/': res = a / b; break;
		}
		printf("%d %c %d = %d\n", a, op, b, res);
		flag = 0;
	}
}

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}
