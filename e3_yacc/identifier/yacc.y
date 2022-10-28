%{
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token digit alpha other

%%
start	: T '\n'		{ printf("Valid Computer Identifier\n"); return 0; };
T		: alpha U
		;
U		: U alpha
		| U digit
		|
		;	
%%

void yyerror() {
	printf("Error. Failed to parse.\n");
}

void main() {
	printf("Enter identifier: \n");
	yyparse();
}
