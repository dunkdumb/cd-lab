#include<stdio.h>
#include<ctype.h>

char input[100];
int i = 0;

void E(); void EP(); void T(); void TP(); void F();

/* E -> T E' */
void E()  { T(); EP(); }

/* E' -> + T E' | epsilon */
void EP()
{
    if(input[i] == '+')
    {
        i++;    /* consume + */
        T();
        EP();
    }
}

/* T -> F T' */
void T()  { F(); TP(); }

/* T' -> * F T' | epsilon */
void TP()
{
    if(input[i] == '*')
    {
        i++;    /* consume * */
        F();
        TP();
    }
}

/* F -> (E) | id */
void F()
{
    if(isalnum(input[i]))
    {
        i++;    /* consume id */
    }
    else if(input[i] == '(')
    {
        i++;        /* consume ( */
        E();
        if(input[i] == ')')
            i++;    /* consume ) */
        else
        {
            printf("Invalid\n");
            i = -1;
        }
    }
    else
    {
        printf("Invalid\n");
        i = -1;
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", input);
    E();
    if(i != -1 && input[i] == '\0')
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}
