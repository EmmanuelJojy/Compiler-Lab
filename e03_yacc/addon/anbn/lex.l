%{
	#include <stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
a { return 'a'; }
b { return 'b'; }
. { return other; }
\n { return '\n'; }
%%