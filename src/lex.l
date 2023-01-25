%{
#include <stdio.h>
#include <stdlib.h>

enum Token {
    // it's important that this starts at 1
    T_BREAK = 1,
    T_IF,
    T_ELSE,
    T_FOR,
    T_FUNC,
    T_RETURN,
    T_VAR,
    T_IDENTIFIER,
    T_INT_LIT
}; 

uint64_t lineno;
uint64_t charno;
%}

/* flex declarations */

/* always have this for school server */
%option noyywrap

/* rules; i.e. mapping of patterns (regex) to actions */
/* no return in actions will keep going; no tokens returned */
alph    [a-zA-Z]
alphNum [a-zA-Z0-9]
letter  [a-zA-Z\_]
digit   [0-9]
letdig  {letter}|{digit}

%%
[ \t]+                  { charno += yyleng; }
\n                      { charno = 0; lineno++; }
"break"                 { return T_BREAK; }
"if"                    { return T_IF; }
"else"                  { return T_ELSE; }
"for"                   { return T_FOR; }
"func"                  { return T_FUNC; }
"return"                { return T_RETURN; }
"var"                   { return T_VAR; }
{letter}({letdig}*)     { return T_IDENTIFIER; }
{digit}({digit}*)       { return T_INT_LIT; }
.                       { charno += yyleng; fprintf(stderr, "lexer error \"%s\"\n", yytext); }
%%

/* whatever c code we want to write */

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    // yylex will run until EOF (returns 0)
    enum Token currentToken;
    while((currentToken = yylex()) != 0) {
        printf("the token we just lexed is %s at line number %lu, char number %lu with type %i\n", yytext, lineno, charno, currentToken);
        charno += yyleng;
    }    //calls lexer; i.e. execute patterns/actions on stdin by default
}