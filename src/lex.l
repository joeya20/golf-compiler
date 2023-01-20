%{
    #include <stdio.h>    
%}

/* flex declarations */

/* always have this for school server */
%option noyywrap

%% 
    /* rules; i.e. mapping of patterns (regex) to actions */
banana  { fprintf(stdout, "Hello World!"); } 
%%

/* whatever c code we want to write */

int main() {
    yylex();    //calls lexer; i.e. execute patterns/actions on stdin by default
}