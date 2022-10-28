%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	#include <string.h>
	int yylex();
	void yyerror();
%}

%union {
	char *str;
};

%token other operand
%type <str> T start operand

%left '+' '-'
%left '*' '/'

%%
start	: T '\n' 		{ printf("Postfix Expression:\t%s\n", $$); return 0; }
		;
T		: T '+' T 		{ sprintf($$, "%s%s+", $1, $3); }
		| T '-' T 		{ sprintf($$, "%s%s-", $1, $3); }
		| T '*' T 		{ sprintf($$, "%s%s*", $1, $3); }
		| T '/' T 		{ sprintf($$, "%s%s/", $1, $3); }
		| '(' T ')'		{ $$ = strdup($2); }
		| operand 		{ $$ = strdup($1); }
		;
%%

void yyerror() {
	printf("Error. Failed to parse.\n");
}

void main() {
	printf("Infix expression:\t");
	yyparse();
}
