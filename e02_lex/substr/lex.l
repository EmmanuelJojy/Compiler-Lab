%{
	#include <stdio.h>
%}

%%
abc		{ printf("ABC"); }
.|\n 	{ printf("%s", yytext); }
%%

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}