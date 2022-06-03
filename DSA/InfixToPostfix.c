#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


char expstack[100];
char opstack[100];
int etop = -1, otop = -1, n = 100;


void Push(int c, char data)
{
    switch(c)
    {
        case 1:
            if (etop ==  100)
                printf("\nOverflow");

            else
            {
                etop++;

                expstack[etop] = data;
            }
            break;
        case 2:
            if (otop ==  100)
            printf("\nOverflow");

            else
            {
                otop++;

                opstack[otop] = data;
            }
            break;
    }
}

char Pop(int c)
{
    char popped;

    switch(c)
    {
        case 1:
            if(etop == -1)
            {
                printf("Underflow\n");
                exit(1);
            }
            
            else
            {
                popped = expstack[etop];
                etop--;
                return(popped);
            }
            break;
        case 2:
            if(otop == -1)
            {
                printf("Underflow\n");
                exit(1);
            }
            
            else
            {
                popped = opstack[otop];
                otop--;
                return(popped);
            }
            break;
    }

    return 0;
}

void Print(int c)
{
    switch(c)
    {
        case 1:
            printf("Postfix = ");
            for(int i = 0; i <= etop; i++)
            {
                printf("%c", expstack[i]);
            }

            if(etop == -1)
            {
                printf("Empty Stack\n");
            }
            break;
        case 2:
            for(int i = 0; i <=otop; i++)
            {
                printf("%c ", opstack[i]);
            }

            if(otop == -1)
            {
                printf("Empty Stack\n");
            }
            break;
    }
}


int main()
{
    char expression[100];
    char original[100];
    printf("Expression: ");
    scanf("%s", expression);

    strcpy(original, expression);
    int len = strlen(expression);

    int count = 0;

    while(count < len)
    {
        char temp = expression[count];

        if(temp == '(' || temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^')
        {
            if(otop >= 0)
            {
                char pop = Pop(2);
                if(pop != '(' && temp != '(')
                    Push(1, pop);
                else
                    Push(2, pop);
            }
            Push(2, temp);
            count++;
        }
        else if(temp == ')')
        {
            char popped = Pop(2);
            while(popped != '(')
            {
                Push(1, popped);
                popped = Pop(2);
            }
            count++;
        }
        else
        {
            Push(1, temp);
            count++;
        }
    }

    Print(1);

    printf("\n");
}