%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token NUM other
%left '+' '-'
%left '*' '/'

%%
start	: T '\n' 	{ printf("Result: %d\n", $$); return 0; };
T		: T '+' T 	{ $$ = $1 + $3; }
		| T '-' T 	{ $$ = $1 - $3; } 
		| T '*' T 	{ $$ = $1 * $3; }
		| T '/' T 	{ $$ = $1 / $3; }
		| '(' T ')' { $$ = $2; }
		| NUM 		{ $$ = $1; }
		;
%%

void yyerror() {
	printf("Error. Failed to parse.\n");
}

void main() {
	printf("Enter arithmetic expression: ");
	yyparse();
}
