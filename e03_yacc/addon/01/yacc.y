%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token other

%%
start	:	T '\n' { printf("Valid String\n"); return 0; }
T		:	'0' U '0'
		|	'1' U '1'
		;
U		:	U '1'
		|	U '0'
		|	U other
		|
		;
%%

void yyerror() {
	printf("Error. Failed to parse.\n");
}

void main() {
	printf("Enter expression: ");
	yyparse();
}