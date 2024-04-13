/***
In this program a DFA has been designed, with alphabet {0, 1},
that accepts strings with an odd number of 0s or an 
even number of 1s, but not both simultaneously.

Input a string containing 0s and 1s only.
Transition table for the DFA:

states\token    0           1           \n(enter)       .(invalid)
INITIAL         Q3          Q1          INITIAL         DEAD
Q1              Q2          INITIAL     Q1              DEAD
Q2              Q1          Q3          Q2              DEAD
Q3              INITIAL     Q2          Q3              DEAD
DEAD            DEAD        DEAD        DEAD            DEAD
***/
%{
%}
%s Q1 Q2 Q3 DEAD

%%
<INITIAL>0 BEGIN Q3;
<INITIAL>1 BEGIN Q1;
<INITIAL>\n BEGIN INITIAL; {printf("Accepted\n"); return 0;}
<INITIAL>. BEGIN DEAD;

<Q1>0 BEGIN Q2;
<Q1>1 BEGIN INITIAL;
<Q1>\n BEGIN Q1; {printf("Rejected\n"); return 0;}
<Q1>. BEGIN DEAD;

<Q2>0 BEGIN Q1;
<Q2>1 BEGIN Q3;
<Q2>\n BEGIN Q2; {printf("Accepted\n"); return 0;}
<Q2>. BEGIN DEAD;

<Q3>0 BEGIN INITIAL;
<Q3>1 BEGIN Q2;
<Q3>\n BEGIN Q3; {printf("Rejected\n"); return 0;}
<Q3>. BEGIN DEAD;

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
