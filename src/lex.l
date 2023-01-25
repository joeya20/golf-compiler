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
    T_LOG_AND,
    T_LOG_EQ,
    T_LOG_NEQ,
    T_LOG_NOT,
    T_LOG_OR,
    T_LOG_LT,
    T_LOG_LTE,
    T_LOG_GT,
    T_LOG_GTE,
    T_ADD,
    T_SUB,
    T_MULT,
    T_DIV,
    T_MOD,
    T_EQ,
    T_COMMA,
    T_SEMICOLON,
    T_OP_BRACKET,
    T_CL_BRACKET,
    T_OP_CUR_BRACKET,
    T_CL_CUR_BRACKET,
    T_IDENTIFIER,
    T_INT_LIT,
    T_STR_LIT
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
"&&"                    { return T_LOG_AND; }
"=="                    { return T_LOG_EQ; }
"!="                    { return T_LOG_NEQ; }
"!"                     { return T_LOG_NOT; }
"||"                    { return T_LOG_OR; }
"<"                     { return T_LOG_LT; }
"<="                    { return T_LOG_LTE; }
">"                     { return T_LOG_GT; }
">="                    { return T_LOG_GTE; }
"+"                     { return T_ADD; }
"-"                     { return T_SUB; }
"*"                     { return T_MULT; }
"/"                     { return T_DIV; }
"%"                     { return T_MOD; }
"="                     { return T_EQ; }
","                     { return T_COMMA; }
";"                     { return T_SEMICOLON; }
"("                     { return T_OP_BRACKET; }
")"                     { return T_CL_BRACKET; }
"{"                     { return T_OP_CUR_BRACKET; }
"}"                     { return T_CL_CUR_BRACKET; }
{letter}({letdig}*)     { return T_IDENTIFIER; }
{digit}({digit}*)       { return T_INT_LIT; }
.                       { charno += yyleng; fprintf(stderr, "lexer error \"%s\"\n", yytext); }
%%

/* whatever c code we want to write */

int main(int argc, char *argv[]) {
    if(argc >= 1) {
        yyin = fopen(argv[1], "r");
    }
    else {
        //TODO: throw error
    }

    if(yyin == NULL) {
        //TODO: use error routine
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