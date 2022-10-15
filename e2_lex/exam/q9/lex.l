%{
#include <stdio.h>
int isLeap(char *);
%}
%%
[0-9]+ { if(isLeap(yytext)) printf("%s: Leap\n", yytext); else printf("%s: Not Leap\n", yytext); }
(.|\n) { ; }
%%

int isLeap(char *yytext) {
	int n;
	sscanf(yytext, "%d", &n);
	if(n % 4 == 0)
		return 1;
	return 0;
}

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}
