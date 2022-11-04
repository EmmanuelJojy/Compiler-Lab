%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
%}

%%
.* { yylval.str = strdup(yytext); return word; }
\n { return '\n'; }
%%
