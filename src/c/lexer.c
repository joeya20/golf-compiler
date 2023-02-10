#include "lexer.h"

// get next token from input stream
// and update charno
int lex() {
    int token = yylex();
    charno += yyleng;
    return token;
}

// convert token enum to string for printing
const char* tokenToString(const enum Token token) {
    switch(token) {
        case T_BREAK:
            return "T_BREAK";
        case T_IF:
            return "T_IF";
        case T_ELSE:
            return "T_ELSE";
        case T_FOR:
            return "T_FOR";
        case T_FUNC:
            return "T_FUNC";
        case T_RETURN:
            return "T_RETURN";
        case T_VAR:
            return "T_VAR";
        case T_AND:
            return "T_AND";
        case T_EQ:
            return "T_EQ";
        case T_NEQ:
            return "T_NEQ";
        case T_NOT:
            return "T_NOT";
        case T_OR:
            return "T_OR";
        case T_LT:
            return "T_LT";
        case T_LTE:
            return "T_LTE";
        case T_GT:
            return "T_GT";
        case T_GTE:
            return "T_GTE";
        case T_ADD:
            return "T_ADD";
        case T_SUB:
            return "T_SUB";
        case T_MULT:
            return "T_MULT";
        case T_DIV:
            return "T_DIV";
        case T_MOD:
            return "T_MOD";
        case T_ASSIGN:
            return "T_ASSIGN";
        case T_COMMA:
            return "T_COMMA";
        case T_SEMICOLON:
            return "T_SEMICOLON";
        case T_LPAREN:
            return "T_LPAREN";
        case T_RPAREN:
            return "T_RPAREN";
        case T_LBRACE:
            return "T_LBRACE";
        case T_RBRACE:
            return "T_RBRACE";
        case T_IDENTIFIER:
            return "T_IDENTIFIER";
        case T_BOOL_LIT:
            return "T_BOOL_LIT";
        case T_INT_LIT:
            return "T_INT_LIT";
        case T_STR_LIT:
            return "T_STR_LIT";
        default:
            return "Invalid token";
    }
}