%{
	// flex lex.l && gcc -g -o lex lex.yy.c -ll && ./lex
	// Experiment 2 x1
	// Lines, words, characters
	#include <stdio.h>
	int lines = 1, char_count = 0, words = 0;
%}

%%
\n { lines++; }
[a-zA-Z_]* {words++; char_count += yyleng; }
. { char_count++; }
%%

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	printf("Statistics:\n%d\tLines\n%d\tCharacters\n%d\tWords\n", lines, char_count, words);
	fclose(yyin);
}

