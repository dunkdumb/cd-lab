%{
    #include<stdio.h>
    int vowels = 0, consonants = 0;
%}

vowel    [aeiouAEIOU]
letter   [a-zA-Z]

%%

{vowel}     { vowels++; }
{letter}    { consonants++; }
[ \t\n]+    ;
.           ;

%%

int main()
{
    printf("Enter a string: ");
    yylex();
    printf("Vowels     : %d\n", vowels);
    printf("Consonants : %d\n", consonants);
    return 0;
}

int yywrap()
{
    return 1;
}
