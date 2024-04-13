/***Lex program that calculates the count of words, special characters, lines,
spaces, and tabs within an English paragraph.
***/
%{
#include <stdbool.h>
int words = 0;
int special_char = 0;
int lines = 1;
int spaces = 0;
int tabs = 0;
bool isAlphanumeric(char c);
// printf("hello");
%}

/*** Rule section
***/
%%
[^ \n\t]+   {
                words++;
                for(int i=0; i<yyleng; i++)
                {
                    if(!isAlphanumeric(yytext[i]))
                        special_char++;
                }
            }
[ ]         {spaces++; }
[\n]        {lines++; }
[\t]        {tabs++; }
%%

/*** User code section ***/
bool isAlphanumeric(char c) 
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

int yywrap() { return 1;}
int main(int argc, char **argv) 
{
    printf("Enter a paragraph:\n");
    yylex();
    printf("\nWord count: %d\n", words);
    printf("Special character count: %d\n", special_char);
    printf("Line count: %d\n", lines);
    printf("Space count: %d\n", spaces);
    printf("Tab count: %d\n", tabs);
    return 0;
}
