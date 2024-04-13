#include <stdio.h>
#include <string.h>

int main() 
{
    char production[3][10];     // three production rules
    char subproduction[2][5];   // max two subrules
    char rule[5];
    char nonterminal;
    char alpha[5];
    char beta[5];

    strcpy(production[0], "E->E+T|T");
    strcpy(production[1], "T->T*F|F");
    strcpy(production[2], "F->id");

    for(int i = 0; i < 3; i++) 
    {
        printf("Production rule: %s\n", production[i]);
        nonterminal = production[i][0];

        // separating individual rules
        int k = 0;
        rule[0] = '\0'; // reset rule
        for (int j = 3; j < 10; j++) 
        {
            if (production[i][j] == '\0') 
            {
                strcpy(subproduction[k], rule);
                break;
            } 
            else if (production[i][j] == '|') 
            {
                strcpy(subproduction[k], rule);
                rule[0] = '\0'; // reset rule
                k++;
            } 
            else 
            {
                strncat(rule, &production[i][j], 1); // concatenate character to rule
            }
        }
        for (int r = 0; r <= k; r++) 
        {
            if(subproduction[r][0] == nonterminal)
            {
                printf("Rule is left recursive\n");
                strcpy(alpha, subproduction[r] + 1);
                strcpy(beta, subproduction[r+1]);
                printf("Non left recursive grammar :\n");
                printf("%c->%s%c'\n", nonterminal, beta, nonterminal);
                printf("%c'->%s%c'|%s\n", nonterminal, alpha, nonterminal, "\u03B5");
                break;
            }
            else
            {
                printf("Not left recursive\n");
            }
        }
        printf("\n");
    }

    return 0;
}
