/***
In this program a DFA has been designed, with alphabet {a, b},
that accepts strings that start with b and end with a.

Input a string containing a's and b's only.
The transition function is as follows:

states\token        a           b           \n(enter)       .(invalid)
INITIAL             Q2          Q1          Q1              DEAD
Q1                  FINAL       Q1          Q1              DEAD
Q2                  Q2          Q2          Q1              DEAD
FINAL               Q1          Q1          Q1              DEAD
DEAD                DEAD        DEAD        DEAD            DEAD
***/
%{
%}

%s Q1 Q2 FINAL DEAD

%%
<INITIAL>a BEGIN Q2;
<INITIAL>b BEGIN Q1;
<INITIAL>\n BEGIN Q1; {printf("Rejected\n"); return 0;}
<INITIAL>. BEGIN DEAD;

<Q1>a BEGIN FINAL;
<Q1>b BEGIN Q1;
<Q1>\n BEGIN Q1; {printf("Rejected\n"); return 0;}
<Q1>. BEGIN DEAD;

<Q2>[ab\n] BEGIN Q2; {printf("Rejected\n"); return 0;}
<Q2>. BEGIN DEAD;

<FINAL>a BEGIN Q1;
<FINAL>b BEGIN Q1;
<FINAL>\n BEGIN Q1; {printf("Accepted\n"); return 0;}
<FINAL>. BEGIN DEAD;

<DEAD>. BEGIN DEAD; {printf("Invalid Input!\n"); return 0;}
%%

/* Main code section*/
int yywrap(){}
int main() 
{
    printf("Input: ");
    yylex();
    return 0;
}
