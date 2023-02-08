%{
	#include <stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
0 { return '0'; }
1 { return '1'; }
. { return other; }
\n { return '\n'; }
%%