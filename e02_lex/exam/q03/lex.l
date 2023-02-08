%{
#include <stdio.h>
%}
%%
"//".*\n { ; }
"/*"(.|\n)*"*/" { ; }
(.|\n) {printf("%s", yytext); }
%%
void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}