/***
In this program a DFA has been designed, with alphabet {a, b},
that accepts strings with an odd number of b's.

Input a string containing a's and b's only.

There are three states in the DFA: INITIAL, Q, DEAD. 
The transition function is as follows:

states\token        a           b           \n(enter)       .(invalid)
INITIAL             INITIAL     Q           INITIAL         DEAD
Q                   Q           INITIAL     INITIAL         DEAD
DEAD                DEAD        DEAD        DEAD            DEAD
***/
%{
%}

%s Q DEAD

%%
<INITIAL>a BEGIN INITIAL; 
<INITIAL>b BEGIN Q; 
<INITIAL>[^ab\n] BEGIN DEAD; 
<INITIAL>\n BEGIN INITIAL; {printf("Rejected\n"); return 0;} 

<Q>a BEGIN Q; 
<Q>b BEGIN INITIAL; 
<Q>[^ab\n] BEGIN DEAD; 
<Q>\n BEGIN INITIAL; {printf("Accepted\n"); return 0;} 

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
