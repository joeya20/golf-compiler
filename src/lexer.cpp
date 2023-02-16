#include "lexer.hpp"

namespace GoLF {

Lexer::Lexer(std::istream& istream, std::ostream& ostream): yyFlexLexer(istream, ostream) {
    currentTokenKind = Parser::symbol_kind_type::S_YYEOF;
    eofReached = false;
    startPos = position(&inputFileName, 1, 1);
}

// convert token enum to string for printing
const char* Lexer::symbolToString(const GoLF::Parser::symbol_type& symbol) {
    return "";
}

// wrapper around lex() to do some internal stuff
// gets called by bison parser
Parser::symbol_type Lexer::getNextToken() {
    if(eofReached) {
        return Parser::make_YYEOF(location{startPos});
    }
    Parser::symbol_type token = lex();
    currentTokenKind = token.kind();
    return token;
}

// checks if a semicolon must be inserted based on currentTokenKind
bool Lexer::checkCurrentToken() {
    return 
    (
        currentTokenKind == Parser::symbol_kind_type::S_ID || 
        currentTokenKind == Parser::symbol_kind_type::S_INT_LIT || 
        currentTokenKind == Parser::symbol_kind_type::S_STR_LIT || 
        currentTokenKind == Parser::symbol_kind_type::S_BREAK || 
        currentTokenKind == Parser::symbol_kind_type::S_RETURN ||
        currentTokenKind == Parser::symbol_kind_type::S_RPAREN ||
        currentTokenKind == Parser::symbol_kind_type::S_RBRACE
    );
}

}