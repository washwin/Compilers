/***
In this program a DFA has been designed, with alphabet {a, b},
that accepts strings that contain the substring 'baba'.

Input a string containing a's and b's only.
The transition function is as follows:

states\token        a           b           \n(enter)       .(invalid)
INITIAL             INITIAL     Q1          Q1              DEAD
Q1                  Q2          INITIAL     Q1              DEAD
Q2                  INITIAL     Q3          Q2              DEAD
Q3                  FINAL       Q1          Q3              DEAD
FINAL               FINAL       FINAL       FINAL           DEAD
DEAD                DEAD        DEAD        DEAD            DEAD
***/
%{
%}

%s Q1 Q2 Q3 FINAL DEAD

%%
<INITIAL>a BEGIN INITIAL;
<INITIAL>b BEGIN Q1;
<INITIAL>\n BEGIN Q1; {printf("Rejected\n"); return 0;}
<INITIAL>. BEGIN DEAD;

<Q1>a BEGIN Q2;
<Q1>b BEGIN INITIAL;
<Q1>\n BEGIN Q1; {printf("Rejected\n"); return 0;}
<Q1>. BEGIN DEAD;

<Q2>a BEGIN INITIAL;
<Q2>b BEGIN Q3;
<Q2>\n BEGIN Q2; {printf("Rejected\n"); return 0;}
<Q2>. BEGIN DEAD;

<Q3>a BEGIN FINAL;
<Q3>b BEGIN Q1;
<Q3>\n BEGIN Q3; {printf("Rejected\n"); return 0;}
<Q3>. BEGIN DEAD;

<FINAL>a BEGIN FINAL;
<FINAL>b BEGIN FINAL;
<FINAL>\n BEGIN FINAL; {printf("Accepted\n"); return 0;}
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
