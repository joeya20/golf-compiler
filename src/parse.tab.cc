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
      case symbol_kind::S_FuncSign: // FuncSign
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_ParamList: // ParamList
      case symbol_kind::S_ParamDecl: // ParamDecl
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
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
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
      case symbol_kind::S_FuncSign: // FuncSign
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_ParamList: // ParamList
      case symbol_kind::S_ParamDecl: // ParamDecl
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
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
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
      case symbol_kind::S_FuncSign: // FuncSign
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_ParamList: // ParamList
      case symbol_kind::S_ParamDecl: // ParamDecl
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
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
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
      case symbol_kind::S_FuncSign: // FuncSign
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_ParamList: // ParamList
      case symbol_kind::S_ParamDecl: // ParamDecl
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
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
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
      case symbol_kind::S_FuncSign: // FuncSign
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_ParamList: // ParamList
      case symbol_kind::S_ParamDecl: // ParamDecl
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
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_Arguments: // Arguments
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
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
#line 114 "src/parse.y"
                                        { root = new AstNode(AstNode::Kind::Program); }
#line 907 "src/parse.tab.cc"
    break;

  case 3: // SourceFile: SourceFile Program $end
#line 115 "src/parse.y"
                                        { /* Janky workaround; maybe fix one day */   }
#line 913 "src/parse.tab.cc"
    break;

  case 4: // Program: TopLevelDecl ";"
#line 119 "src/parse.y"
                                        { root->addChild(yystack_[1].value.as < AstNode* > ()); }
#line 919 "src/parse.tab.cc"
    break;

  case 5: // Program: Program TopLevelDecl ";"
#line 120 "src/parse.y"
                                        { root->addChild(yystack_[1].value.as < AstNode* > ()); }
#line 925 "src/parse.tab.cc"
    break;

  case 6: // TopLevelDecl: GlobVarDecl
#line 124 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 931 "src/parse.tab.cc"
    break;

  case 7: // TopLevelDecl: FuncDecl
#line 125 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 937 "src/parse.tab.cc"
    break;

  case 8: // GlobVarDecl: "var" ID Type
#line 129 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::GlobVarDecl);
                                    AstNode *id = new AstNode(AstNode::Kind::Ident, yystack_[1].value.as < std::string > ());
                                    yylhs.value.as < AstNode* > ()->addChild(id); 
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                                }
#line 948 "src/parse.tab.cc"
    break;

  case 9: // VarDecl: "var" ID Type
#line 138 "src/parse.y"
                        { 
                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::VarDecl);
                            AstNode *id = new AstNode(AstNode::Kind::Ident, yystack_[1].value.as < std::string > ());
                            yylhs.value.as < AstNode* > ()->addChild(id); 
                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                        }
#line 959 "src/parse.tab.cc"
    break;

  case 10: // Type: ID
#line 147 "src/parse.y"
                { 
                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Type, yystack_[0].value.as < std::string > ()); 
                }
#line 967 "src/parse.tab.cc"
    break;

  case 11: // FuncDecl: "func" ID FuncSign Block
#line 153 "src/parse.y"
                                        { 
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::FuncDecl);
                                            AstNode* id = new AstNode(AstNode::Kind::Ident, yystack_[2].value.as < std::string > ());
                                            yylhs.value.as < AstNode* > ()->addChild(id);
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 979 "src/parse.tab.cc"
    break;

  case 12: // FuncSign: Params
#line 163 "src/parse.y"
                            { 
                                yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::FuncSign);
                                AstNode* type = new AstNode(AstNode::Kind::Type, "$void"); 
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                yylhs.value.as < AstNode* > ()->addChild(type);
                            }
#line 990 "src/parse.tab.cc"
    break;

  case 13: // FuncSign: Params Type
#line 169 "src/parse.y"
                            {
                                yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::FuncSign);
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                            }
#line 1000 "src/parse.tab.cc"
    break;

  case 14: // Params: "(" ")"
#line 177 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Params); }
#line 1006 "src/parse.tab.cc"
    break;

  case 15: // Params: "(" ParamList ")"
#line 178 "src/parse.y"
                                        { 
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Params);
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                        }
#line 1015 "src/parse.tab.cc"
    break;

  case 16: // Params: "(" ParamList "," ")"
#line 182 "src/parse.y"
                                        { 
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Params);
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                        }
#line 1024 "src/parse.tab.cc"
    break;

  case 17: // ParamList: ParamDecl
#line 189 "src/parse.y"
                                        { 
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ParamList);
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1033 "src/parse.tab.cc"
    break;

  case 18: // ParamList: ParamList "," ParamDecl
#line 193 "src/parse.y"
                                        { 
                                            yystack_[2].value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                        }
#line 1042 "src/parse.tab.cc"
    break;

  case 19: // ParamDecl: ID Type
#line 200 "src/parse.y"
                        { 
                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ParamDecl);
                            AstNode* id = new AstNode(AstNode::Kind::Ident, yystack_[1].value.as < std::string > ());
                            yylhs.value.as < AstNode* > ()->addChild(id);
                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                        }
#line 1053 "src/parse.tab.cc"
    break;

  case 20: // Block: "{" StmtList "}"
#line 209 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Block);
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                }
#line 1062 "src/parse.tab.cc"
    break;

  case 21: // StmtList: %empty
#line 216 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::StmtList); }
#line 1068 "src/parse.tab.cc"
    break;

  case 22: // StmtList: StmtList Stmt ";"
#line 217 "src/parse.y"
                                {
                                    yystack_[2].value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                    yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                }
#line 1077 "src/parse.tab.cc"
    break;

  case 23: // Stmt: VarDecl
#line 224 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1083 "src/parse.tab.cc"
    break;

  case 24: // Stmt: SimpleStmt
#line 225 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1089 "src/parse.tab.cc"
    break;

  case 25: // Stmt: ReturnStmt
#line 226 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1095 "src/parse.tab.cc"
    break;

  case 26: // Stmt: BreakStmt
#line 227 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1101 "src/parse.tab.cc"
    break;

  case 27: // Stmt: Block
#line 228 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1107 "src/parse.tab.cc"
    break;

  case 28: // Stmt: IfStmt
#line 229 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1113 "src/parse.tab.cc"
    break;

  case 29: // Stmt: ForStmt
#line 230 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1119 "src/parse.tab.cc"
    break;

  case 30: // SimpleStmt: EmptyStmt
#line 234 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1125 "src/parse.tab.cc"
    break;

  case 31: // SimpleStmt: ExprStmt
#line 235 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1131 "src/parse.tab.cc"
    break;

  case 32: // SimpleStmt: AssignStmt
#line 236 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1137 "src/parse.tab.cc"
    break;

  case 33: // ReturnStmt: "return"
#line 240 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ReturnStmt); }
#line 1143 "src/parse.tab.cc"
    break;

  case 34: // ReturnStmt: "return" Expr
#line 241 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ReturnStmt);
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                }
#line 1152 "src/parse.tab.cc"
    break;

  case 35: // BreakStmt: "break"
#line 248 "src/parse.y"
                      { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BreakStmt); }
#line 1158 "src/parse.tab.cc"
    break;

  case 36: // IfStmt: "if" Expr Block
#line 252 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::IfStmt);
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1168 "src/parse.tab.cc"
    break;

  case 37: // IfStmt: "if" Expr Block ElseStmt
#line 257 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::IfStmt);
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1179 "src/parse.tab.cc"
    break;

  case 38: // ElseStmt: "else" IfStmt
#line 266 "src/parse.y"
                                        {
                                            // just return the IfStmt
                                            yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > ();
                                        }
#line 1188 "src/parse.tab.cc"
    break;

  case 39: // ElseStmt: "else" Block
#line 270 "src/parse.y"
                                        {
                                            // just return the block
                                            yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > ();
                                        }
#line 1197 "src/parse.tab.cc"
    break;

  case 40: // ForStmt: "for" Block
#line 277 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ForStmt); 
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                                }
#line 1206 "src/parse.tab.cc"
    break;

  case 41: // ForStmt: "for" Expr Block
#line 281 "src/parse.y"
                                { 
                                    yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ForStmt);
                                    //intentionally add Expr after Block
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ()); 
                                }
#line 1217 "src/parse.tab.cc"
    break;

  case 42: // EmptyStmt: %empty
#line 290 "src/parse.y"
                      { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::EmptyStmt); }
#line 1223 "src/parse.tab.cc"
    break;

  case 43: // ExprStmt: Expr
#line 294 "src/parse.y"
                    { 
                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ExprStmt);
                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ()); 
                    }
#line 1232 "src/parse.tab.cc"
    break;

  case 44: // AssignStmt: Expr "=" Expr
#line 301 "src/parse.y"
                            {   
                                yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::AssignStmt); 
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ()); 
                                yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                            }
#line 1242 "src/parse.tab.cc"
    break;

  case 45: // ExprList: Expr
#line 309 "src/parse.y"
                                    { 
                                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ExprList);
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    }
#line 1251 "src/parse.tab.cc"
    break;

  case 46: // ExprList: ExprList "," Expr
#line 313 "src/parse.y"
                                    { 
                                        yystack_[2].value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > ();
                                    }
#line 1260 "src/parse.tab.cc"
    break;

  case 47: // Expr: Expr "||" AndExpr
#line 320 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[1].value.as < std::string > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1270 "src/parse.tab.cc"
    break;

  case 48: // Expr: AndExpr
#line 325 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1276 "src/parse.tab.cc"
    break;

  case 49: // AndExpr: AndExpr "&&" RelExpr
#line 329 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[1].value.as < std::string > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1286 "src/parse.tab.cc"
    break;

  case 50: // AndExpr: RelExpr
#line 334 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1292 "src/parse.tab.cc"
    break;

  case 51: // RelExpr: RelExpr RelOp AddExpr
#line 338 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1302 "src/parse.tab.cc"
    break;

  case 52: // RelExpr: AddExpr
#line 343 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1308 "src/parse.tab.cc"
    break;

  case 53: // AddExpr: AddExpr AddOp MultExpr
#line 347 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1318 "src/parse.tab.cc"
    break;

  case 54: // AddExpr: MultExpr
#line 352 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1324 "src/parse.tab.cc"
    break;

  case 55: // MultExpr: MultExpr MultOp UnaryExpr
#line 356 "src/parse.y"
                                        {
                                            yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[2].value.as < AstNode* > ());
                                            yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                        }
#line 1334 "src/parse.tab.cc"
    break;

  case 56: // MultExpr: UnaryExpr
#line 361 "src/parse.y"
                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1340 "src/parse.tab.cc"
    break;

  case 57: // UnaryExpr: PrimaryExpr
#line 365 "src/parse.y"
                                    {
                                        yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > ();    
                                    }
#line 1348 "src/parse.tab.cc"
    break;

  case 58: // UnaryExpr: UnaryOp UnaryExpr
#line 368 "src/parse.y"
                                    {
                                        yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > ();
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    }
#line 1357 "src/parse.tab.cc"
    break;

  case 59: // PrimaryExpr: Operand
#line 375 "src/parse.y"
                                    { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 1363 "src/parse.tab.cc"
    break;

  case 60: // PrimaryExpr: FuncCall
#line 376 "src/parse.y"
                                    { std::cout << "prim" << std::endl; }
#line 1369 "src/parse.tab.cc"
    break;

  case 61: // FuncCall: Operand Arguments
#line 380 "src/parse.y"
                                    {
                                        yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::FuncCall);
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[1].value.as < AstNode* > ());
                                        yylhs.value.as < AstNode* > ()->addChild(yystack_[0].value.as < AstNode* > ());
                                    }
#line 1379 "src/parse.tab.cc"
    break;

  case 62: // Arguments: "(" ")"
#line 387 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::ExprList); }
#line 1385 "src/parse.tab.cc"
    break;

  case 63: // Arguments: "(" ExprList ")"
#line 388 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 1391 "src/parse.tab.cc"
    break;

  case 64: // Arguments: "(" ExprList "," ")"
#line 389 "src/parse.y"
                                            { yylhs.value.as < AstNode* > () = yystack_[2].value.as < AstNode* > (); }
#line 1397 "src/parse.tab.cc"
    break;

  case 65: // Operand: INT_LIT
#line 393 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::IntLit, yystack_[0].value.as < std::string > ()); }
#line 1403 "src/parse.tab.cc"
    break;

  case 66: // Operand: STR_LIT
#line 394 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::StrLit, yystack_[0].value.as < std::string > ()); }
#line 1409 "src/parse.tab.cc"
    break;

  case 67: // Operand: ID
#line 395 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::Ident, yystack_[0].value.as < std::string > ()); }
#line 1415 "src/parse.tab.cc"
    break;

  case 68: // Operand: "(" Expr ")"
#line 396 "src/parse.y"
                                { yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 1421 "src/parse.tab.cc"
    break;

  case 69: // UnaryOp: "-"
#line 400 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::UnaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1427 "src/parse.tab.cc"
    break;

  case 70: // UnaryOp: "!"
#line 401 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::UnaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1433 "src/parse.tab.cc"
    break;

  case 71: // RelOp: "=="
#line 405 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1439 "src/parse.tab.cc"
    break;

  case 72: // RelOp: "!="
#line 406 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1445 "src/parse.tab.cc"
    break;

  case 73: // RelOp: "<"
#line 407 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1451 "src/parse.tab.cc"
    break;

  case 74: // RelOp: "<="
#line 408 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1457 "src/parse.tab.cc"
    break;

  case 75: // RelOp: ">"
#line 409 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1463 "src/parse.tab.cc"
    break;

  case 76: // RelOp: ">="
#line 410 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1469 "src/parse.tab.cc"
    break;

  case 77: // AddOp: "+"
#line 414 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1475 "src/parse.tab.cc"
    break;

  case 78: // AddOp: "-"
#line 415 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1481 "src/parse.tab.cc"
    break;

  case 79: // MultOp: "*"
#line 419 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1487 "src/parse.tab.cc"
    break;

  case 80: // MultOp: "/"
#line 420 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1493 "src/parse.tab.cc"
    break;

  case 81: // MultOp: "%"
#line 421 "src/parse.y"
                    { yylhs.value.as < AstNode* > () = new AstNode(AstNode::Kind::BinaryExpr, yystack_[0].value.as < std::string > ()); }
#line 1499 "src/parse.tab.cc"
    break;


#line 1503 "src/parse.tab.cc"

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


  const signed char  Parser ::yypact_ninf_ = -62;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
     -62,     2,   -62,   -19,   -14,     9,    20,   -62,   -62,    22,
      -6,   -62,    31,   -62,    11,    47,    -6,   -62,   -62,   -62,
     -62,    -6,    10,   -62,   -62,   -62,   -62,   -62,   -62,    13,
      18,   -62,   -62,    60,   -62,   -62,   -62,   -62,    60,    48,
      60,    30,   -62,   -62,   -62,   -62,   -62,    62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,    -1,    67,    85,    55,
      83,   -62,   -62,   -62,    64,    60,     8,    84,   -62,    84,
      58,    -6,   -62,    60,    60,    60,   -62,   -62,   -62,   -62,
     -62,   -62,    60,   -62,   -62,    60,   -62,   -62,   -62,    60,
      51,   -62,   -62,   -62,    59,   -62,   -62,    67,    58,    85,
      55,    83,   -62,   -62,    12,    58,     6,   -62,   -62,    56,
     -62,   -62,   -62,    58
  };

  const signed char
   Parser ::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     0,     6,     7,     0,
       0,     3,     0,     4,     0,     0,    12,    10,     8,     5,
      14,     0,     0,    17,    21,    11,    13,    19,    15,     0,
      42,    16,    18,     0,    20,    70,    69,    35,     0,     0,
      33,     0,    65,    66,    67,    23,    27,     0,    24,    25,
      26,    28,    29,    30,    31,    32,    43,    48,    50,    52,
      54,    56,    57,    60,    59,     0,     0,     0,    40,     0,
      34,     0,    22,     0,     0,     0,    71,    72,    73,    74,
      75,    76,     0,    77,    78,     0,    79,    80,    81,     0,
       0,    61,    58,    68,    36,    41,     9,    47,    44,    49,
      51,    53,    55,    62,     0,    45,     0,    37,    63,     0,
      39,    38,    64,    46
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -62,   -62,   -62,    81,   -62,   -62,   -13,   -62,   -62,   -62,
     -62,    68,   -29,   -62,   -62,   -62,   -62,   -62,     0,   -62,
     -62,   -62,   -62,   -62,   -62,   -33,    32,    33,    25,    24,
     -61,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     1,     5,     6,     7,    45,    18,     8,    15,    16,
      22,    23,    25,    30,    47,    48,    49,    50,    51,   107,
      52,    53,    54,    55,   104,    56,    57,    58,    59,    60,
      61,    62,    63,    91,    64,    65,    82,    85,    89
  };

  const signed char
   Parser ::yytable_[] =
  {
      66,    46,     2,    26,    92,    67,    69,    70,    27,    11,
      68,    73,    24,    93,     9,    28,    20,   108,    31,    10,
      73,    74,    33,    13,    24,    34,    14,    17,   102,    35,
       3,    38,     4,    29,    19,   109,    36,     3,    94,     4,
      95,    98,    37,    38,    21,    39,    21,    40,    41,    42,
      43,    44,    33,    24,    24,    33,   103,   105,    96,    35,
      33,   112,    35,    71,    33,    72,    36,    35,    90,    36,
      73,    35,    83,    84,    36,    75,   113,   110,    36,    42,
      43,    44,    42,    43,    44,   106,    12,    42,    43,    44,
      24,    42,    43,    44,    76,    77,    73,    32,    78,    79,
      80,    81,    86,    87,    88,    97,   111,   100,    99,   101
  };

  const signed char
   Parser ::yycheck_[] =
  {
      33,    30,     0,    16,    65,    38,    39,    40,    21,     0,
      39,    12,     6,     5,    33,     5,     5,     5,     5,    33,
      12,    22,     4,     3,     6,     7,     4,    33,    89,    11,
      28,    25,    30,    23,     3,    23,    18,    28,    67,    30,
      69,    74,    24,    25,    33,    27,    33,    29,    30,    31,
      32,    33,     4,     6,     6,     4,     5,    90,    71,    11,
       4,     5,    11,    33,     4,     3,    18,    11,     4,    18,
      12,    11,    17,    18,    18,     8,   109,   106,    18,    31,
      32,    33,    31,    32,    33,    26,     5,    31,    32,    33,
       6,    31,    32,    33,     9,    10,    12,    29,    13,    14,
      15,    16,    19,    20,    21,    73,   106,    82,    75,    85
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    35,     0,    28,    30,    36,    37,    38,    41,    33,
      33,     0,    37,     3,     4,    42,    43,    33,    40,     3,
       5,    33,    44,    45,     6,    46,    40,    40,     5,    23,
      47,     5,    45,     4,     7,    11,    18,    24,    25,    27,
      29,    30,    31,    32,    33,    39,    46,    48,    49,    50,
      51,    52,    54,    55,    56,    57,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    59,    59,    46,    59,
      59,    33,     3,    12,    22,     8,     9,    10,    13,    14,
      15,    16,    70,    17,    18,    71,    19,    20,    21,    72,
       4,    67,    64,     5,    46,    46,    40,    60,    59,    61,
      62,    63,    64,     5,    58,    59,    26,    53,     5,    23,
      46,    52,     5,    59
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    34,    35,    35,    36,    36,    37,    37,    38,    39,
      40,    41,    42,    42,    43,    43,    43,    44,    44,    45,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      49,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    67,    68,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     0,     3,     2,     3,     1,     1,     3,     3,
       1,     4,     1,     2,     2,     3,     4,     1,     3,     2,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     4,     2,     2,
       2,     3,     0,     1,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     2,     2,     3,     4,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "GlobVarDecl", "VarDecl", "Type", "FuncDecl", "FuncSign", "Params",
  "ParamList", "ParamDecl", "Block", "StmtList", "Stmt", "SimpleStmt",
  "ReturnStmt", "BreakStmt", "IfStmt", "ElseStmt", "ForStmt", "EmptyStmt",
  "ExprStmt", "AssignStmt", "ExprList", "Expr", "AndExpr", "RelExpr",
  "AddExpr", "MultExpr", "UnaryExpr", "PrimaryExpr", "FuncCall",
  "Arguments", "Operand", "UnaryOp", "RelOp", "AddOp", "MultOp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   114,   114,   115,   119,   120,   124,   125,   129,   138,
     147,   153,   163,   169,   177,   178,   182,   189,   193,   200,
     209,   216,   217,   224,   225,   226,   227,   228,   229,   230,
     234,   235,   236,   240,   241,   248,   252,   257,   266,   270,
     277,   281,   290,   294,   301,   309,   313,   320,   325,   329,
     334,   338,   343,   347,   352,   356,   361,   365,   368,   375,
     376,   380,   387,   388,   389,   393,   394,   395,   396,   400,
     401,   405,   406,   407,   408,   409,   410,   414,   415,   419,
     420,   421
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
#line 2056 "src/parse.tab.cc"

#line 423 "src/parse.y"


//TODO: call error routine
void GoLF::Parser::error (const location_type& loc, const std::string& msg) {
    std::cerr << msg << '\n';
}
