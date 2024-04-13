#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[] = "a=b*-c+b*-c";          //a=b∗–c+b∗–c
    char op[] = "*/+-";
    int length = 0;
    int j = 1, i, k, l;
    char arg1, arg2;
    printf("sno\targ1\targ2\top\n");
    while (expression[length] != '\0') 
    {
        length++;
    }

    for(i=0; i<length-1; i++)
    {
        if(expression[i] == '-' && !isalpha(expression[i-1]))
        {
            printf("%d\t%c\tNULL\t-\n", j, expression[i+1]);
            expression[i] = 'l' + j;
            expression[i+1] = '\0';
            strcpy(expression + i + 1, expression + i + 2);
            j = j + 1;
            length = length - 1;
        }
    }
    // printf("%s\n", expression);
    for(k=0; k<4; k++)
    {
        for(i=1; i<length-1; i=i+2)
        {
            if(expression[i] == op[k])
            {   
                arg1 = expression[i-1];
                if (arg1 > 108)
                {   
                    arg1 = arg1 - 60;
                }
                arg2 = expression[i+1];
                if (arg2 > 108)
                {
                    arg2 = arg2 - 60;
                }
                printf("%d\t%c\t%c\t%c\n", j, arg1, arg2, op[k]);
                // printf("%s\n", expression);
                expression[i - 1] = 'l' + j;
                expression[i] = '\0';
                strcpy(expression + i, expression + i + 2);
                j = j + 1;
                i = i - 2;
                length = length - 2;
            }
        }
    }

    if(expression[1] == '=')
    {
        printf("%d\t%d\tNULL\t=\n", j, j-1);
    }
    return 0;
}
