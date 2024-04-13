%{
#include "y.tab.h"
extern int yylval;
%}

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z]+       { return ALPHA; }
[\t]+           ;
[\n]            { return '\n'; }
.               { return yytext[0]; }
%%

int yywrap() 
{
    return 101;
}
