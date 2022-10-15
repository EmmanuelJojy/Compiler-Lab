%{
#include <stdio.h>
%}
%%
[+-]?[0-9]*[02468] { printf("%s: Even\n", yytext); }
[+-]?[0-9]*[13579] { printf("%s: Odd\n", yytext); }
(.|\n) { ; }
%%
void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}
