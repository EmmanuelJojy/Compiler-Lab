%{
#include <stdio.h>
int l = 0, s = 0, t = 0;
%}
%%
[\n] { l++; }
[ ] { s++; }
[\t] { t++; }
. {;}
%%
void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	printf("File Stat:\n");
	printf("Lines: %d\nSpaces: %d\nTabs: %d\n", l, s, t);
	fclose(yyin);
}
