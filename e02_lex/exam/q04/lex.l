%{
#include <stdio.h>
%}
%%
[ ]+ { printf(" "); }
(.|\n) {printf("%s", yytext); }
%%
void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}