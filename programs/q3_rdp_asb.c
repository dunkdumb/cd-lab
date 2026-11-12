#include<stdio.h>

char input[100];
int i = 0;

/* S -> aSb | epsilon */
void S()
{
    if(input[i] == 'a')
    {
        i++;           /* match 'a' */
        S();           /* recursive call */
        if(input[i] == 'b')
            i++;       /* match 'b' */
        else
        {
            printf("Invalid\n");
            i = -1;
        }
    }
    /* else epsilon — do nothing */
}

int main()
{
    printf("Enter string: ");
    scanf("%s", input);
    S();
    if(i != -1 && input[i] == '\0')
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}
