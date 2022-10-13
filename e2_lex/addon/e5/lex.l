%{
	// flex lex.l && gcc -g -o lex lex.yy.c -ll && ./lex
	// Experiment 2 x3
	// Real Number Classify
	#include <stdio.h>
	int comment = 0;
%}

%%
[ \n\t] { ; }

[+-]?[0-9]+(\.[0-9]+)?(E[+-]?[0-9]+) { printf("%s\tExponent Number\n", yytext); }
([+-]?[0-9]+)\.[0-9]+ { printf("%s\tFloating Number\n", yytext); }
[+-]?[0-9]+ { printf("%s\tIntegers\n", yytext); }

. { ; }
%%

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}
