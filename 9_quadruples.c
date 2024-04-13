#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[] = "a+b+c*d/e+f";          //a+b+c*d/e+f
    char op[] = "*/+-";
    int length = 0;
    int j = 1, i, k;
    char t1, t2, arg1, arg2;

    printf("sno\ttarget\targ1\targ2\top\n");
    while (expression[length] != '\0') 
    {
        length++;
    }

    for(i=0; i<length-1; i++)
    {
        if(expression[i] == '-' && !isalpha(expression[i-1]))
        {
            printf("%d\tt%d\t%c\tNULL\t-\n", j, j, expression[i+1]);
            expression[i] = 'l' + j;
            expression[i+1] = '\0';
            strcpy(expression + i + 1, expression + i + 2);
            j = j + 1;
            length = length - 1;
        }
    }
    
    if (length == 3)
    {
        printf("%d\t%c\t%c\tNULL\t=\n", j, expression[0], expression[2]);
        return 0;
    }

    for(k=0; k<4; k++)
    {
        for(i=1; i<length-1; i=i+2)
        {
            if(expression[i] == op[k])
            {
                t1 = '\0';
                t2 = '\0';
                arg1 = expression[i-1];
                if (arg1 > 108)
                {   
                    arg1 = arg1 - 60;
                    t1 = 't';
                }
                arg2 = expression[i+1];
                if (arg2 > 108)
                {
                    arg2 = arg2 - 60;
                    t2 = 't';
                }
                printf("%d\tt%d\t%c%c\t%c%c\t%c\n", j, j, t1, arg1, t2, arg2, op[k]);
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
        printf("%d\t%c\tt%d\tNULL\t=\n", j, expression[0], j-1);
    }
    return 0;
}
