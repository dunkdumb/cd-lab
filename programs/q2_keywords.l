%{
    #include<stdio.h>
%}

keyword   int|float|char|double|if|else|for|while|return|void
digit     [0-9]
letter    [a-zA-Z]

%%

{keyword}       { printf("Keyword  : %s\n", yytext); }
{digit}+        { printf("Number   : %s\n", yytext); }
{letter}+       { printf("Word     : %s\n", yytext); }
[ \t\n]+        ;
.               { printf("Symbol   : %s\n", yytext); }

%%

int main()
{
    printf("Enter string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
