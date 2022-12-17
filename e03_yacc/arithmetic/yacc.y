%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token NUM ID other
%left '+' '-'
%left '*' '/'

%%
start	: T '\n' 	{ printf("Valid Arithmetic Expression\n"); return 0; };
T		: T '+' T 	
		| T '-' T 	
		| T '*' T 	
		| T '/' T 	
		| '(' T ')' 
		| NUM
		| ID
		;
%%

void yyerror() {
	printf("Error. Failed to parse.\n");
}

void main() {
	printf("Enter arithmetic expression: ");
	yyparse();
}
