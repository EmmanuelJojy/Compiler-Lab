%{
#include <stdio.h>
int maxi = -1;
%}
%%
[a-zA-Z]+ { if(yyleng > maxi) maxi = yyleng; }
(.|\n) { ; }
%%
void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	printf("Length of Longest Word: %d\n",maxi);
	fclose(yyin);
}