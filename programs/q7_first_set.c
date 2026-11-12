#include<stdio.h>
#include<string.h>

char prod[10][10];
char first[26][10];
int n;

int isTerminal(char c)
{
    return !(c >= 'A' && c <= 'Z');
}

void addFirst(int idx, char c)
{
    if(strchr(first[idx], c) == NULL)
    {
        int len = strlen(first[idx]);
        first[idx][len]   = c;
        first[idx][len+1] = '\0';
    }
}

void computeFirst(char c)
{
    int idx = c - 'A';
    if(first[idx][0] != '\0')
        return;

    int i, j;
    for(i = 0; i < n; i++)
    {
        if(prod[i][0] == c)
        {
            char rhs = prod[i][3];
            if(isTerminal(rhs))
            {
                addFirst(idx, rhs);
            }
            else
            {
                computeFirst(rhs);
                int rIdx = rhs - 'A';
                for(j = 0; first[rIdx][j] != '\0'; j++)
                    addFirst(idx, first[rIdx][j]);
            }
        }
    }
}

int main()
{
    int i, j;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (format E->T):\n");
    for(i = 0; i < n; i++)
        scanf("%s", prod[i]);

    memset(first, 0, sizeof(first));
    for(i = 0; i < n; i++)
        computeFirst(prod[i][0]);

    printf("\nFIRST Sets:\n");
    for(i = 0; i < n; i++)
    {
        char sym = prod[i][0];
        printf("FIRST(%c) = { ", sym);
        for(j = 0; first[sym-'A'][j] != '\0'; j++)
            printf("%c ", first[sym-'A'][j]);
        printf("}\n");
    }
    return 0;
}
