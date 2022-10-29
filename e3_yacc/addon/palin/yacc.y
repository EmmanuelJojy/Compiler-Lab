%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	#include <string.h>
	int yylex();
	void yyerror();
%}

%token other sym

%%
start	: T '\n' 		{ printf("Valid Palindrome\n"); return 0; }
		;	
T		: sym T sym		{ printf("%c-%c", $1, $3); return 0; }
		| sym
		|
		;
%%

void yyerror() {
	printf("Invalid Palindrome.\n");
}

void main() {
	#ifdef YYDEBUG
  		yydebug = 1;
	#endif
	printf("Enter palindrome to valid:\t");
	yyparse();
}
