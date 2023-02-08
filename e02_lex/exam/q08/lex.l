%{
#include <stdio.h>
int isPrime(char *);
%}
%%
[0-9]+ { if(isPrime(yytext)) printf("%s: Prime\n", yytext); else printf("%s: Not Prime\n", yytext); }
(.|\n) { ; }
%%

int isPrime(char *yytext) {
	int n;
	sscanf(yytext, "%d", &n);
	if(n < 2)
		return 0;
	for(int i = 2; i <= n / 2; i++)
		if(n % i == 0)
			return 0;
	return 1;
}

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
}