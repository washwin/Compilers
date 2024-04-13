%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *s);

%}

%token NUMBER ALPHA
%left '+' '-' '*' '/' '(' ')'

%name Calculator

%%
grammar: expr '\n' {
    printf("\nArithmetic Expression is Valid\n");
    printf("Result : %d\n", $$);
    exit(0);
}

expr : expr '*' expr {$$ = $1 * $3;}
  | expr '/' expr {
        if ($3 == 0) {
            printf("CANNOT DIVIDE BY ZERO!\n");
            exit(0);
        } else {
            $$ = $1 / $3;
        }
   }
  | '(' expr ')' {$$ = $2;}
  | expr '+' expr {$$ = $1 + $3;}
  | expr '-' expr {$$ = $1 - $3;}
  | '-' expr    {$$ = -$2;}
  | NUMBER {$$ = $1;}
  | ALPHA { printf("INVALID INPUT!\n");exit(0); } 
  ;
%%

int main()
{
    printf("Enter the Arithmetic Expression : ");
    yyparse();
    return 0;
}


void yyerror(char *errormsg)
{
    printf("Arithmetic Expression is INVALID!\n%s\n", errormsg);
    exit(1);
}


