%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token other

%%
start	:	T '\n' { printf("Valid String\n"); return 0; }
T		:	'a' T 'b'
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
