%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
%}

%%
[a-zA-Z0-9]+ { yylval.str = strdup(yytext); return operand; }
[+\-*/()] { return yytext[0]; }
. { return other; }
\n { return '\n'; }
%%
