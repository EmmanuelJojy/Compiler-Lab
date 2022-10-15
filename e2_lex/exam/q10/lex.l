%{
#include <stdio.h>
int isArm(char *);
%}
%%
[0-9]+ { if(isArm(yytext)) printf("%s: Armstrong\n", yytext); else printf("%s: Not Armstrong\n", yytext); }
(.|\n) { ; }
%%

int isArm(char *yytext) {
	int n;
	sscanf(yytext, "%d", &n);
	int copy = n, sum = 0, dig = 0;
	while( n != 0) {
		dig = n % 10;
		sum += dig * dig * dig;
		n /= 10;
	}
	if(sum == copy)
		return 1;
	return 0;
}

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}
