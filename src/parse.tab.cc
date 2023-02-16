// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 20 "src/parse.y"

    #include <FlexLexer.h>
    #include "lexer.hpp"
    GoLF::Parser::symbol_type yylex(GoLF::Lexer &lexer) {
        return lexer.getNextToken();
    }

#line 47 "src/parse.tab.cc"




#include "parse.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 30 "src/parse.y"
namespace  GoLF  {
#line 147 "src/parse.tab.cc"

  /// Build a parser object.
   Parser :: Parser  (Lexer &lexer_yyarg, AstNode *& root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TopLevelDecl: // TopLevelDecl
      case symbol_kind::S_GlobVarDecl: // GlobVarDecl
      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_FuncDecl: // FuncDecl
      case symbol_kind::S_FuncName: // FuncName
      case symbol_kind::S_FuncBody: // FuncBody
      case symbol_kind::S_Signature: // Signature
      case symbol_kind::S_Parameters: // Parameters
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_ParameterDecl: // ParameterDecl
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
      case symbol_kind::S_Block: // Block
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_SimpleStmt: // SimpleStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_BreakStmt: // BreakStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_ElseStmt: // ElseStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_EmptyStmt: // EmptyStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
      case symbol_kind::S_AssignStmt: // AssignStmt
        value.YY_MOVE_OR_COPY< AstNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_AND: // "&&"
      case symbol_kind::S_EQ: // "=="
      case symbol_kind::S_NEQ: // "!="
      case symbol_kind::S_NOT: // "!"
      case symbol_kind::S_OR: // "||"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LTE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GTE: // ">="
      case symbol_kind::S_ADD: // "+"
      case symbol_kind::S_SUB: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIV: // "/"
      case symbol_kind::S_MOD: // "%"
      case symbol_kind::S_ASSIGN: // "="
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_FUNC: // "func"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_INT_LIT: // INT_LIT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TopLevelDecl: // TopLevelDecl
      case symbol_kind::S_GlobVarDecl: // GlobVarDecl
      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_FuncDecl: // FuncDecl
      case symbol_kind::S_FuncName: // FuncName
      case symbol_kind::S_FuncBody: // FuncBody
      case symbol_kind::S_Signature: // Signature
      case symbol_kind::S_Parameters: // Parameters
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_ParameterDecl: // ParameterDecl
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
      case symbol_kind::S_Block: // Block
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_SimpleStmt: // SimpleStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_BreakStmt: // BreakStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_ElseStmt: // ElseStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_EmptyStmt: // EmptyStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
      case symbol_kind::S_AssignStmt: // AssignStmt
        value.move< AstNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_AND: // "&&"
      case symbol_kind::S_EQ: // "=="
      case symbol_kind::S_NEQ: // "!="
      case symbol_kind::S_NOT: // "!"
      case symbol_kind::S_OR: // "||"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LTE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GTE: // ">="
      case symbol_kind::S_ADD: // "+"
      case symbol_kind::S_SUB: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIV: // "/"
      case symbol_kind::S_MOD: // "%"
      case symbol_kind::S_ASSIGN: // "="
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_FUNC: // "func"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_INT_LIT: // INT_LIT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TopLevelDecl: // TopLevelDecl
      case symbol_kind::S_GlobVarDecl: // GlobVarDecl
      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_FuncDecl: // FuncDecl
      case symbol_kind::S_FuncName: // FuncName
      case symbol_kind::S_FuncBody: // FuncBody
      case symbol_kind::S_Signature: // Signature
      case symbol_kind::S_Parameters: // Parameters
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_ParameterDecl: // ParameterDecl
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
      case symbol_kind::S_Block: // Block
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_SimpleStmt: // SimpleStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_BreakStmt: // BreakStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_ElseStmt: // ElseStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_EmptyStmt: // EmptyStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
      case symbol_kind::S_AssignStmt: // AssignStmt
        value.copy< AstNode* > (that.value);
        break;

      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_AND: // "&&"
      case symbol_kind::S_EQ: // "=="
      case symbol_kind::S_NEQ: // "!="
      case symbol_kind::S_NOT: // "!"
      case symbol_kind::S_OR: // "||"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LTE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GTE: // ">="
      case symbol_kind::S_ADD: // "+"
      case symbol_kind::S_SUB: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIV: // "/"
      case symbol_kind::S_MOD: // "%"
      case symbol_kind::S_ASSIGN: // "="
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_FUNC: // "func"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_INT_LIT: // INT_LIT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TopLevelDecl: // TopLevelDecl
      case symbol_kind::S_GlobVarDecl: // GlobVarDecl
      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_FuncDecl: // FuncDecl
      case symbol_kind::S_FuncName: // FuncName
      case symbol_kind::S_FuncBody: // FuncBody
      case symbol_kind::S_Signature: // Signature
      case symbol_kind::S_Parameters: // Parameters
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_ParameterDecl: // ParameterDecl
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
      case symbol_kind::S_Block: // Block
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_SimpleStmt: // SimpleStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_BreakStmt: // BreakStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_ElseStmt: // ElseStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_EmptyStmt: // EmptyStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
      case symbol_kind::S_AssignStmt: // AssignStmt
        value.move< AstNode* > (that.value);
        break;

      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_AND: // "&&"
      case symbol_kind::S_EQ: // "=="
      case symbol_kind::S_NEQ: // "!="
      case symbol_kind::S_NOT: // "!"
      case symbol_kind::S_OR: // "||"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LTE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GTE: // ">="
      case symbol_kind::S_ADD: // "+"
      case symbol_kind::S_SUB: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIV: // "/"
      case symbol_kind::S_MOD: // "%"
      case symbol_kind::S_ASSIGN: // "="
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_FUNC: // "func"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_INT_LIT: // INT_LIT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (lexer));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TopLevelDecl: // TopLevelDecl
      case symbol_kind::S_GlobVarDecl: // GlobVarDecl
      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_FuncDecl: // FuncDecl
      case symbol_kind::S_FuncName: // FuncName
      case symbol_kind::S_FuncBody: // FuncBody
      case symbol_kind::S_Signature: // Signature
      case symbol_kind::S_Parameters: // Parameters
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_ParameterDecl: // ParameterDecl
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
      case symbol_kind::S_Block: // Block
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_SimpleStmt: // SimpleStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_BreakStmt: // BreakStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_ElseStmt: // ElseStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_EmptyStmt: // EmptyStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
      case symbol_kind::S_AssignStmt: // AssignStmt
        yylhs.value.emplace< AstNode* > ();
        break;

      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_AND: // "&&"
      case symbol_kind::S_EQ: // "=="
      case symbol_kind::S_NEQ: // "!="
      case symbol_kind::S_NOT: // "!"
      case symbol_kind::S_OR: // "||"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LTE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GTE: // ">="
      case symbol_kind::S_ADD: // "+"
      case symbol_kind::S_SUB: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIV: // "/"
      case symbol_kind::S_MOD: // "%"
      case symbol_kind::S_ASSIGN: // "="
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_FUNC: // "func"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_INT_LIT: // INT_LIT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // SourceFile: %empty
#line 115 "src/parse.y"
                                           { root = new AstNode(AstNode::Kind::Program); }
#line 912 "src/parse.tab.cc"
    break;

  case 3: // SourceFile: SourceFile Program $end
#line 116 "src/parse.y"
                                           { /* Janky workaround; maybe fix one day */ }
#line 918 "src/parse.tab.cc"
    break;

  case 4: // Program: TopLevelDecl ";"
#line 119 "src/parse.y"
                                        { root->addChild(yystack_[1].value.as < AstNode* > ()); }
#line 924 "src/parse.tab.cc"
    break;

  case 5: // Program: Program TopLevelDecl ";"
#line 120 "src/parse.y"
                                        { root->addChild(yystack_[1].value.as < AstNode* > ()); }
#line 930 "src/parse.tab.cc"
    break;

  case 6: // TopLevelDecl: GlobVarDecl
#line 124 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 936 "src/parse.tab.cc"
    break;

  case 7: // TopLevelDecl: FuncDecl
#line 125 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 942 "src/parse.tab.cc"
    break;

  case 8: // GlobVarDecl: "var" ID Type
#line 129 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::GlobVarDecl);
                                    AstNode *id = new AstNode(AstNode::Kind::Ident, yystack_[1].value.as < std::string > ());
                                    yylhs.value.as < AstNode* > ()->addChild(id); 
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                                }
#line 953 "src/parse.tab.cc"
    break;

  case 9: // VarDecl: "var" ID Type
#line 137 "src/parse.y"
                        { 
                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::VarDecl);
                            AstNode *id = new AstNode(AstNode::Kind::Ident, yystack_[1].value.as < std::string > ());
                            yylhs.value.as < AstNode* > ()->addChild(id); 
                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                        }
#line 964 "src/parse.tab.cc"
    break;

  case 10: // Type: ID
#line 146 "src/parse.y"
                { 
                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Ident, yystack_[0].value.as < std::string > ()); 
                }
#line 972 "src/parse.tab.cc"
    break;

  case 11: // FuncDecl: "func" FuncName Signature FuncBody
#line 152 "src/parse.y"
                                                 { std::cout << "funcdecl" << std::endl; }
#line 978 "src/parse.tab.cc"
    break;

  case 12: // FuncName: ID
#line 157 "src/parse.y"
                    { 
                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Ident, yystack_[0].value.as < std::string > ()); 
                        }
#line 986 "src/parse.tab.cc"
    break;

  case 13: // FuncBody: Block
#line 164 "src/parse.y"
                    {
                            yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > ();
                        }
#line 994 "src/parse.tab.cc"
    break;

  case 14: // Signature: Parameters
#line 170 "src/parse.y"
                                    { 
                                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::FuncSignStmt);
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    }
#line 1003 "src/parse.tab.cc"
    break;

  case 15: // Signature: Parameters ID
#line 174 "src/parse.y"
                                    { 
                                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::FuncSignStmt);
                                        AstNode* id = new AstNode(AstNode::Kind::Ident, yystack_[0].value.as < std::string > ());
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                        yylhs.value.as < AstNode* > ()->addChild(id);
                                    }
#line 1014 "src/parse.tab.cc"
    break;

  case 16: // Parameters: "(" ")"
#line 183 "src/parse.y"
                                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::EmptyStmt); }
#line 1020 "src/parse.tab.cc"
    break;

  case 17: // Parameters: "(" ParameterList ")"
#line 184 "src/parse.y"
                                                { 
                                                    yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                                }
#line 1028 "src/parse.tab.cc"
    break;

  case 18: // Parameters: "(" ParameterList "," ")"
#line 187 "src/parse.y"
                                                { 
                                                    yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                                }
#line 1036 "src/parse.tab.cc"
    break;

  case 19: // ParameterList: ParameterDecl
#line 193 "src/parse.y"
                                                    { 
                                                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ParameterList);
                                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                                    }
#line 1045 "src/parse.tab.cc"
    break;

  case 20: // ParameterList: ParameterList "," ParameterDecl
#line 197 "src/parse.y"
                                                    { 
                                                        yystack_[2].value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                                        yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                                    }
#line 1054 "src/parse.tab.cc"
    break;

  case 21: // ParameterDecl: ID Type
#line 204 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ParameterDecl);
                                    AstNode* id = new AstNode(AstNode::Kind::Ident, yystack_[1].value.as < std::string > ());
                                    yylhs.value.as < AstNode* > ()->addChild(id);
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                }
#line 1065 "src/parse.tab.cc"
    break;

  case 22: // Operand: INT_LIT
#line 213 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::IntLit, yystack_[0].value.as < std::string > ()); }
#line 1071 "src/parse.tab.cc"
    break;

  case 23: // Operand: STR_LIT
#line 214 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::StrLit, yystack_[0].value.as < std::string > ()); }
#line 1077 "src/parse.tab.cc"
    break;

  case 24: // Operand: ID
#line 215 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Ident, yystack_[0].value.as < std::string > ()); }
#line 1083 "src/parse.tab.cc"
    break;

  case 25: // Operand: "(" Expr ")"
#line 216 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 1089 "src/parse.tab.cc"
    break;

  case 26: // PrimaryExpr: Operand
#line 220 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1095 "src/parse.tab.cc"
    break;

  case 27: // PrimaryExpr: PrimaryExpr Arguments
#line 221 "src/parse.y"
                                            { std::cout << "prim" << std::endl; }
#line 1101 "src/parse.tab.cc"
    break;

  case 28: // Arguments: "(" ")"
#line 225 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::EmptyStmt); }
#line 1107 "src/parse.tab.cc"
    break;

  case 29: // Arguments: "(" ExprList ")"
#line 226 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 1113 "src/parse.tab.cc"
    break;

  case 30: // Arguments: "(" ExprList "," ")"
#line 227 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > (); }
#line 1119 "src/parse.tab.cc"
    break;

  case 31: // ExprList: Expr
#line 231 "src/parse.y"
                                    { 
                                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ExprList);
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    }
#line 1128 "src/parse.tab.cc"
    break;

  case 32: // ExprList: ExprList "," Expr
#line 235 "src/parse.y"
                                    { 
                                        yystack_[2].value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                    }
#line 1137 "src/parse.tab.cc"
    break;

  case 33: // Expr: Expr "||" AndExpr
#line 242 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[1].value.as < std::string > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1147 "src/parse.tab.cc"
    break;

  case 34: // Expr: AndExpr
#line 247 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1153 "src/parse.tab.cc"
    break;

  case 35: // AndExpr: AndExpr "&&" RelExpr
#line 251 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[1].value.as < std::string > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1163 "src/parse.tab.cc"
    break;

  case 36: // AndExpr: RelExpr
#line 256 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1169 "src/parse.tab.cc"
    break;

  case 37: // RelExpr: RelExpr RelOp AddExpr
#line 260 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1179 "src/parse.tab.cc"
    break;

  case 38: // RelExpr: AddExpr
#line 265 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1185 "src/parse.tab.cc"
    break;

  case 39: // AddExpr: AddExpr AddOp MultExpr
#line 269 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1195 "src/parse.tab.cc"
    break;

  case 40: // AddExpr: MultExpr
#line 274 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1201 "src/parse.tab.cc"
    break;

  case 41: // MultExpr: MultExpr MultOp UnaryExpr
#line 278 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1211 "src/parse.tab.cc"
    break;

  case 42: // MultExpr: UnaryExpr
#line 283 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1217 "src/parse.tab.cc"
    break;

  case 43: // UnaryExpr: PrimaryExpr
#line 287 "src/parse.y"
                                    {
                                        //skip creating a redundant UnaryExpr node
                                        //and just point directly to the PrimaryExpr
                                        yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > ();    
                                    }
#line 1227 "src/parse.tab.cc"
    break;

  case 44: // UnaryExpr: UnaryOp UnaryExpr
#line 292 "src/parse.y"
                                    {
                                        yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    }
#line 1236 "src/parse.tab.cc"
    break;

  case 45: // UnaryOp: "-"
#line 299 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1242 "src/parse.tab.cc"
    break;

  case 46: // UnaryOp: "!"
#line 300 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1248 "src/parse.tab.cc"
    break;

  case 47: // RelOp: "=="
#line 304 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1254 "src/parse.tab.cc"
    break;

  case 48: // RelOp: "!="
#line 305 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1260 "src/parse.tab.cc"
    break;

  case 49: // RelOp: "<"
#line 306 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1266 "src/parse.tab.cc"
    break;

  case 50: // RelOp: "<="
#line 307 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1272 "src/parse.tab.cc"
    break;

  case 51: // RelOp: ">"
#line 308 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1278 "src/parse.tab.cc"
    break;

  case 52: // RelOp: ">="
#line 309 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1284 "src/parse.tab.cc"
    break;

  case 53: // AddOp: "+"
#line 313 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1290 "src/parse.tab.cc"
    break;

  case 54: // AddOp: "-"
#line 314 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1296 "src/parse.tab.cc"
    break;

  case 55: // MultOp: "*"
#line 318 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1302 "src/parse.tab.cc"
    break;

  case 56: // MultOp: "/"
#line 319 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1308 "src/parse.tab.cc"
    break;

  case 57: // MultOp: "%"
#line 320 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1314 "src/parse.tab.cc"
    break;

  case 58: // Block: "{" StmtList "}"
#line 324 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Block);
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                }
#line 1323 "src/parse.tab.cc"
    break;

  case 59: // StmtList: %empty
#line 331 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::StmtList); }
#line 1329 "src/parse.tab.cc"
    break;

  case 60: // StmtList: StmtList Stmt ";"
#line 332 "src/parse.y"
                                {
                                    yystack_[2].value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                    yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                }
#line 1338 "src/parse.tab.cc"
    break;

  case 61: // Stmt: VarDecl
#line 339 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1344 "src/parse.tab.cc"
    break;

  case 62: // Stmt: SimpleStmt
#line 340 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1350 "src/parse.tab.cc"
    break;

  case 63: // Stmt: ReturnStmt
#line 341 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1356 "src/parse.tab.cc"
    break;

  case 64: // Stmt: BreakStmt
#line 342 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1362 "src/parse.tab.cc"
    break;

  case 65: // Stmt: Block
#line 343 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1368 "src/parse.tab.cc"
    break;

  case 66: // Stmt: IfStmt
#line 344 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1374 "src/parse.tab.cc"
    break;

  case 67: // Stmt: ForStmt
#line 345 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1380 "src/parse.tab.cc"
    break;

  case 68: // SimpleStmt: EmptyStmt
#line 349 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1386 "src/parse.tab.cc"
    break;

  case 69: // SimpleStmt: ExprStmt
#line 350 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1392 "src/parse.tab.cc"
    break;

  case 70: // SimpleStmt: AssignStmt
#line 351 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1398 "src/parse.tab.cc"
    break;

  case 71: // ReturnStmt: "return"
#line 355 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ReturnStmt); }
#line 1404 "src/parse.tab.cc"
    break;

  case 72: // ReturnStmt: "return" Expr
#line 356 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ReturnStmt);
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                }
#line 1413 "src/parse.tab.cc"
    break;

  case 73: // BreakStmt: "break"
#line 363 "src/parse.y"
                      { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BreakStmt); }
#line 1419 "src/parse.tab.cc"
    break;

  case 74: // IfStmt: "if" Expr Block
#line 367 "src/parse.y"
                                        { std::cout << "if" << std::endl; }
#line 1425 "src/parse.tab.cc"
    break;

  case 75: // IfStmt: "if" Expr Block ElseStmt
#line 368 "src/parse.y"
                                        { std::cout << "if" << std::endl; }
#line 1431 "src/parse.tab.cc"
    break;

  case 76: // ElseStmt: "else" IfStmt
#line 372 "src/parse.y"
                                        { std::cout << "else" << std::endl; }
#line 1437 "src/parse.tab.cc"
    break;

  case 77: // ElseStmt: "else" Block
#line 373 "src/parse.y"
                                        { std::cout << "else" << std::endl; }
#line 1443 "src/parse.tab.cc"
    break;

  case 78: // ForStmt: "for" Block
#line 377 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ForStmt); 
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                                }
#line 1452 "src/parse.tab.cc"
    break;

  case 79: // ForStmt: "for" Expr Block
#line 381 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ForStmt);
                                    //intentionally add Expr after Block
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ()); 
                                }
#line 1463 "src/parse.tab.cc"
    break;

  case 80: // EmptyStmt: %empty
#line 390 "src/parse.y"
                      { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::EmptyStmt); }
#line 1469 "src/parse.tab.cc"
    break;

  case 81: // ExprStmt: Expr
#line 394 "src/parse.y"
                    { 
                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ExprStmt);
                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                    }
#line 1478 "src/parse.tab.cc"
    break;

  case 82: // AssignStmt: Expr "=" Expr
#line 401 "src/parse.y"
                            {   
                                yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::AssignStmt); 
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ()); 
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                            }
#line 1488 "src/parse.tab.cc"
    break;


#line 1492 "src/parse.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser ::context.
   Parser ::context::context (const  Parser & yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser ::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
   Parser ::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser ::yypact_ninf_ = -55;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
     -55,     4,   -55,   -23,    -9,    14,    44,   -55,   -55,   -55,
      45,    19,   -55,    51,   -55,     3,    50,    25,   -55,   -55,
     -55,   -55,    19,     8,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,    15,    39,   -55,   -55,    75,   -55,   -55,   -55,   -55,
      75,    49,    75,    26,   -55,   -55,   -55,   -55,   -55,    57,
      -3,    54,    12,     0,    68,   -55,    75,   -55,    62,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,    11,    23,    23,
     -55,    61,    19,    72,   -55,    75,    75,    75,   -55,   -55,
     -55,   -55,   -55,   -55,    75,   -55,   -55,    75,   -55,   -55,
     -55,    75,   -55,   -55,   -55,    48,   -55,   -55,   -55,    10,
      61,    54,    61,    12,     0,    68,   -55,     5,   -55,   -55,
      80,   -55,   -55,   -55,    61
  };

  const signed char
   Parser ::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     0,     6,     7,    12,
       0,     0,     3,     0,     4,     0,     0,    14,    10,     8,
       5,    16,     0,     0,    19,    59,    11,    13,    15,    21,
      17,     0,    80,    18,    20,     0,    58,    46,    45,    73,
       0,     0,    71,     0,    22,    23,    24,    61,    26,    43,
      81,    34,    36,    38,    40,    42,     0,    65,     0,    62,
      63,    64,    66,    67,    68,    69,    70,     0,     0,     0,
      78,    72,     0,     0,    27,     0,     0,     0,    47,    48,
      49,    50,    51,    52,     0,    53,    54,     0,    55,    56,
      57,     0,    44,    60,    25,    74,    79,     9,    28,     0,
      31,    33,    82,    35,    37,    39,    41,     0,    75,    29,
       0,    77,    76,    30,    32
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -55,   -55,   -55,    87,   -55,   -55,   -21,   -55,   -55,   -55,
     -55,   -55,   -55,    63,   -55,   -55,   -55,   -55,   -35,    20,
      22,    13,     9,   -54,   -55,   -55,   -55,   -55,   -29,   -55,
     -55,   -55,   -55,   -55,    -7,   -55,   -55,   -55,   -55,   -55
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     1,     5,     6,     7,    47,    19,     8,    10,    26,
      16,    17,    23,    24,    48,    49,    74,    99,    50,    51,
      52,    53,    54,    55,    56,    84,    87,    91,    27,    32,
      58,    59,    60,    61,    62,   108,    63,    64,    65,    66
  };

  const signed char
   Parser ::yytable_[] =
  {
      67,    29,    92,    57,     2,    68,    69,    71,    21,    75,
       9,    25,    70,    30,    12,   109,    94,    85,    86,    76,
      33,    78,    79,    75,    11,    80,    81,    82,    83,    25,
      40,    31,     3,   110,     4,    75,    22,   106,   100,    95,
      96,   102,     3,    35,     4,    25,    36,    14,    22,    15,
      37,    97,    18,    35,    20,    25,    25,    38,    28,    72,
      37,    73,    77,    39,    40,    93,    41,    38,    42,    43,
      44,    45,    46,    75,   107,   114,    35,    98,   111,    35,
      44,    45,    46,    37,    35,   113,    37,    88,    89,    90,
      38,    37,    13,    38,    34,   101,   105,   104,    38,   103,
     112,     0,     0,    44,    45,    46,    44,    45,    46,     0,
       0,    44,    45,    46
  };

  const signed char
   Parser ::yycheck_[] =
  {
      35,    22,    56,    32,     0,    40,    41,    42,     5,    12,
      33,     6,    41,     5,     0,     5,     5,    17,    18,    22,
       5,     9,    10,    12,    33,    13,    14,    15,    16,     6,
      25,    23,    28,    23,    30,    12,    33,    91,    73,    68,
      69,    76,    28,     4,    30,     6,     7,     3,    33,     4,
      11,    72,    33,     4,     3,     6,     6,    18,    33,    33,
      11,     4,     8,    24,    25,     3,    27,    18,    29,    30,
      31,    32,    33,    12,    26,   110,     4,     5,   107,     4,
      31,    32,    33,    11,     4,     5,    11,    19,    20,    21,
      18,    11,     5,    18,    31,    75,    87,    84,    18,    77,
     107,    -1,    -1,    31,    32,    33,    31,    32,    33,    -1,
      -1,    31,    32,    33
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    35,     0,    28,    30,    36,    37,    38,    41,    33,
      42,    33,     0,    37,     3,     4,    44,    45,    33,    40,
       3,     5,    33,    46,    47,     6,    43,    62,    33,    40,
       5,    23,    63,     5,    47,     4,     7,    11,    18,    24,
      25,    27,    29,    30,    31,    32,    33,    39,    48,    49,
      52,    53,    54,    55,    56,    57,    58,    62,    64,    65,
      66,    67,    68,    70,    71,    72,    73,    52,    52,    52,
      62,    52,    33,     4,    50,    12,    22,     8,     9,    10,
      13,    14,    15,    16,    59,    17,    18,    60,    19,    20,
      21,    61,    57,     3,     5,    62,    62,    40,     5,    51,
      52,    53,    52,    54,    55,    56,    57,    26,    69,     5,
      23,    62,    68,     5,    52
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    34,    35,    35,    36,    36,    37,    37,    38,    39,
      40,    41,    42,    43,    44,    44,    45,    45,    45,    46,
      46,    47,    48,    48,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      71,    72,    73
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     0,     3,     2,     3,     1,     1,     3,     3,
       1,     4,     1,     1,     1,     2,     2,     3,     4,     1,
       3,     2,     1,     1,     1,     3,     1,     2,     2,     3,
       4,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     4,     2,     2,     2,     3,
       0,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\";\"", "\"(\"",
  "\")\"", "\"{\"", "\"}\"", "\"&&\"", "\"==\"", "\"!=\"", "\"!\"",
  "\"||\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"%\"", "\"=\"", "\",\"", "\"break\"", "\"if\"",
  "\"else\"", "\"for\"", "\"func\"", "\"return\"", "\"var\"", "INT_LIT",
  "STR_LIT", "ID", "$accept", "SourceFile", "Program", "TopLevelDecl",
  "GlobVarDecl", "VarDecl", "Type", "FuncDecl", "FuncName", "FuncBody",
  "Signature", "Parameters", "ParameterList", "ParameterDecl", "Operand",
  "PrimaryExpr", "Arguments", "ExprList", "Expr", "AndExpr", "RelExpr",
  "AddExpr", "MultExpr", "UnaryExpr", "UnaryOp", "RelOp", "AddOp",
  "MultOp", "Block", "StmtList", "Stmt", "SimpleStmt", "ReturnStmt",
  "BreakStmt", "IfStmt", "ElseStmt", "ForStmt", "EmptyStmt", "ExprStmt",
  "AssignStmt", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   115,   115,   116,   119,   120,   124,   125,   129,   137,
     146,   152,   157,   164,   170,   174,   183,   184,   187,   193,
     197,   204,   213,   214,   215,   216,   220,   221,   225,   226,
     227,   231,   235,   242,   247,   251,   256,   260,   265,   269,
     274,   278,   283,   287,   292,   299,   300,   304,   305,   306,
     307,   308,   309,   313,   314,   318,   319,   320,   324,   331,
     332,   339,   340,   341,   342,   343,   344,   345,   349,   350,
     351,   355,   356,   363,   367,   368,   372,   373,   377,   381,
     390,   394,   401
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 30 "src/parse.y"
} //  GoLF 
#line 2048 "src/parse.tab.cc"

#line 407 "src/parse.y"


//TODO: call error routine
void GoLF::Parser::error (const location_type& loc, const std::string& msg) {
    std::cerr << msg << '\n';
}
