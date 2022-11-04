%{
	// yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
	#include <stdio.h>
	#include <string.h>
	int yylex();
	void yyerror();
	int palin(char *);
%}

%union {
	char *str;
};


%token word
%type <str> start word

%%
start	: word '\n' 	{ 
							if(palin($1)) printf("Valid Palindrome\n");
							else printf("Not a Palindrome\n");
							return 0; 
						}
		;
%%

int palin(char *s) {
	int i = 0, j = strlen(s) - 1;
	while(i < j) {
		if(s[i] != s[j]) return 0;
		i++; j--;
	}
	return 1;
}

void yyerror() {
	printf("Invalid Palindrome.\n");
}

void main() {
	printf("Enter palindrome to valid:\t");
	yyparse();
}
