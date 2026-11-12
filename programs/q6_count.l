%{
    #include<stdio.h>
    int lines = 0, words = 0, spaces = 0, characters = 0;
%}

word    [a-zA-Z]+
space   [ \t]

%%

{word}      { words++; characters += yyleng; }
\n          { lines++; }
{space}     { spaces++; }
.           { characters++; }

%%

int main()
{
    printf("Enter text (Ctrl+D to stop):\n");
    yylex();
    printf("Lines      : %d\n", lines);
    printf("Words      : %d\n", words);
    printf("Spaces     : %d\n", spaces);
    printf("Characters : %d\n", characters);
    return 0;
}

int yywrap()
{
    return 1;
}
