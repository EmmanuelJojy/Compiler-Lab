%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
%}

%%
. { yylval.str = strdup(yytext); return sym; }
\n { return '\n'; }
%%
