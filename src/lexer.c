#include "lexer.h"

int lex() {
    return yylex();
}

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
        case T_LOG_AND:
            return "T_LOG_AND";
        case T_LOG_EQ:
            return "T_LOG_EQ";
        case T_LOG_NEQ:
            return "T_LOG_NEQ";
        case T_LOG_NOT:
            return "T_LOG_NOT";
        case T_LOG_OR:
            return "T_LOG_OR";
        case T_LOG_LT:
            return "T_LOG_LT";
        case T_LOG_LTE:
            return "T_LOG_LTE";
        case T_LOG_GT:
            return "T_LOG_GT";
        case T_LOG_GTE:
            return "T_LOG_GTE";
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
        case T_EQ:
            return "T_EQ";
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