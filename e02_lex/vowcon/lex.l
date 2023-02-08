%{
	// flex lex.l && gcc -g -o lex lex.yy.c -ll && ./lex
	// Experiment 2 x2
	// Vowels Consonants
	#include <stdio.h>
	int vowels = 0, cons = 0;
%}

%%
[ \n\t] { ; }
[aeiouAEIOU] { vowels++; }
[a-zA-Z] { cons++; }
. {  }
%%

void main() {
	yyin = fopen("input.txt", "r");
	yylex();
	printf("Statistics:\n%d\tVowels\n%d\tConsonants\n", vowels, cons);
	fclose(yyin);
}