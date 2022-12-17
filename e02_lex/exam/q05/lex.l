%{
#include <stdio.h>
int p = 0, n = 0;
%}
%%
[+]?[0-9]+ { p++; }
[-][0-9]+ { n++; }
(.|\n) { ; }
%%
void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	printf("File Stat\nPositive Integers: %d\nNegative Integers: %d\n", p, n);
	fclose(yyin);
}
