%{
	#include <stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+ { sscanf(yytext, "%d", &yylval); return NUM; }
[+\-*/()] { return yytext[0]; }
. { return other; }
\n { return '\n'; }
%%