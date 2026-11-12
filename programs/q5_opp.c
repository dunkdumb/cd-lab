#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SYMS 8

char symbols[SYMS] = {'i','+','-','*','/','(',')', '$'};

char table[SYMS][SYMS] = {
    /*i*/ { ' ','>','>','>','>',' ','>','>' },
    /*+*/ { '<','>','>','<','<','<','>','>' },
    /*-*/ { '<','>','>','<','<','<','>','>' },
    /***/ { '<','>','>','>','>','<','>','>' },
    /*/*/ { '<','>','>','>','>','<','>','>' },
    /*(*/ { '<','<','<','<','<','<','=',' ' },
    /*)*/ { ' ','>','>','>','>',' ','>','>' },
    /*$*/ { '<','<','<','<','<','<',' ',' ' }
};

int symIndex(char c)
{
    int k;
    for(k = 0; k < SYMS; k++)
        if(symbols[k] == c) return k;
    return -1;
}

char stack[100];
int top = -1;

void push(char c) { stack[++top]=c; stack[top+1]='\0'; }
char pop()        { char c=stack[top--]; stack[top+1]='\0'; return c; }
char peek()       { return stack[top]; }

int main()
{
    char input[100], buf[100];
    int ip=0, len, k, j=0;
    stack[0]='\0';

    printf("Enter expression (use i for id, e.g. i+i*i): ");
    scanf("%s", buf);

    len = strlen(buf);
    for(k=0; k<len; k++) input[j++]=buf[k];
    input[j++]='$'; input[j]='\0';

    push('$');

    printf("\n%-15s %-15s %-10s\n","STACK","INPUT","ACTION");
    printf("------------------------------------------\n");

    while(1)
    {
        char a = peek();
        char b = input[ip];
        printf("%-15s %-15s ", stack, input+ip);

        if(a=='$' && b=='$')
        {
            printf("ACCEPT\n");
            printf("\nExpression is VALID\n");
            break;
        }

        int ai = symIndex(a);
        int bi = symIndex(b);
        if(ai==-1 || bi==-1) { printf("ERROR\n"); break; }

        char rel = table[ai][bi];

        if(rel=='<' || rel=='=')
        {
            printf("SHIFT  %c\n", b);
            push(b); ip++;
        }
        else if(rel=='>')
        {
            char popped;
            do { popped = pop(); }
            while(top>=0 &&
                  table[symIndex(peek())][symIndex(popped)]!='<' &&
                  peek()!='$');
            printf("REDUCE\n");
        }
        else
        {
            printf("ERROR\n");
            printf("\nExpression is INVALID\n");
            break;
        }
    }
    return 0;
}
