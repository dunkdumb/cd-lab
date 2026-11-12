%{
    #include<stdio.h>
    int pos_int = 0, neg_int = 0, pos_frac = 0, neg_frac = 0;
%}

%%

-[0-9]*\.[0-9]+      { neg_frac++; }
[+]?[0-9]*\.[0-9]+   { pos_frac++; }
-[0-9]+              { neg_int++;  }
[+]?[0-9]+           { pos_int++;  }
[ \t\n]+             ;
.                    ;

%%

int main()
{
    printf("Enter numbers (Ctrl+D to stop):\n");
    yylex();
    printf("Positive Integers  : %d\n", pos_int);
    printf("Negative Integers  : %d\n", neg_int);
    printf("Positive Fractions : %d\n", pos_frac);
    printf("Negative Fractions : %d\n", neg_frac);
    return 0;
}

int yywrap()
{
    return 1;
}
