%{
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token NUM
%left '*' '/'
%left '+' '-'

%%
start	: T { printf("Result: %d\n", $$); return 0; };
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
	yyparse();
}
