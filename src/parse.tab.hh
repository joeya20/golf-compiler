// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file src/parse.tab.hh
 ** Define the  GoLF ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_PARSE_TAB_HH_INCLUDED
# define YY_YY_SRC_PARSE_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 5 "src/parse.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include "location.hh"
    #include "AstNode.hpp"
    #include "util.hpp"
    #include <string>
    #include <iostream>
    #include <memory>
    
    //forward declaration needed because we are passing lexer as a param
    namespace GoLF {
        class Lexer;
    }

#line 65 "src/parse.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 31 "src/parse.y"
namespace  GoLF  {
#line 201 "src/parse.tab.hh"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // TopLevelDecl
      // GlobVarDecl
      // VarDecl
      // Type
      // FuncDecl
      // FuncSign
      // Params
      // ParamList
      // ParamDecl
      // Block
      // StmtList
      // Stmt
      // SimpleStmt
      // ReturnStmt
      // BreakStmt
      // IfStmt
      // ElseStmt
      // ForStmt
      // EmptyStmt
      // ExprStmt
      // AssignStmt
      // Expr
      // AndExpr
      // RelExpr
      // AddExpr
      // MultExpr
      // UnaryExpr
      // PrimaryExpr
      // FuncCall
      // FuncArgs
      // ExprList
      // Operand
      // UnaryOp
      // RelOp
      // AddOp
      // MultOp
      char dummy1[sizeof (std::shared_ptr<AstNode>)];

      // ";"
      // "("
      // ")"
      // "{"
      // "}"
      // "&&"
      // "=="
      // "!="
      // "!"
      // "||"
      // "<"
      // "<="
      // ">"
      // ">="
      // "+"
      // "-"
      // "*"
      // "/"
      // "%"
      // "="
      // ","
      // "break"
      // "if"
      // "else"
      // "for"
      // "func"
      // "return"
      // "var"
      // INT_LIT
      // STR_LIT
      // ID
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    SEMICOLON = 258,               // ";"
    LPAREN = 259,                  // "("
    RPAREN = 260,                  // ")"
    LBRACE = 261,                  // "{"
    RBRACE = 262,                  // "}"
    AND = 263,                     // "&&"
    EQ = 264,                      // "=="
    NEQ = 265,                     // "!="
    NOT = 266,                     // "!"
    OR = 267,                      // "||"
    LT = 268,                      // "<"
    LTE = 269,                     // "<="
    GT = 270,                      // ">"
    GTE = 271,                     // ">="
    ADD = 272,                     // "+"
    SUB = 273,                     // "-"
    MULT = 274,                    // "*"
    DIV = 275,                     // "/"
    MOD = 276,                     // "%"
    ASSIGN = 277,                  // "="
    COMMA = 278,                   // ","
    BREAK = 279,                   // "break"
    IF = 280,                      // "if"
    ELSE = 281,                    // "else"
    FOR = 282,                     // "for"
    FUNC = 283,                    // "func"
    RETURN = 284,                  // "return"
    VAR = 285,                     // "var"
    INT_LIT = 286,                 // INT_LIT
    STR_LIT = 287,                 // STR_LIT
    ID = 288                       // ID
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 34, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_SEMICOLON = 3,                         // ";"
        S_LPAREN = 4,                            // "("
        S_RPAREN = 5,                            // ")"
        S_LBRACE = 6,                            // "{"
        S_RBRACE = 7,                            // "}"
        S_AND = 8,                               // "&&"
        S_EQ = 9,                                // "=="
        S_NEQ = 10,                              // "!="
        S_NOT = 11,                              // "!"
        S_OR = 12,                               // "||"
        S_LT = 13,                               // "<"
        S_LTE = 14,                              // "<="
        S_GT = 15,                               // ">"
        S_GTE = 16,                              // ">="
        S_ADD = 17,                              // "+"
        S_SUB = 18,                              // "-"
        S_MULT = 19,                             // "*"
        S_DIV = 20,                              // "/"
        S_MOD = 21,                              // "%"
        S_ASSIGN = 22,                           // "="
        S_COMMA = 23,                            // ","
        S_BREAK = 24,                            // "break"
        S_IF = 25,                               // "if"
        S_ELSE = 26,                             // "else"
        S_FOR = 27,                              // "for"
        S_FUNC = 28,                             // "func"
        S_RETURN = 29,                           // "return"
        S_VAR = 30,                              // "var"
        S_INT_LIT = 31,                          // INT_LIT
        S_STR_LIT = 32,                          // STR_LIT
        S_ID = 33,                               // ID
        S_YYACCEPT = 34,                         // $accept
        S_SourceFile = 35,                       // SourceFile
        S_Program = 36,                          // Program
        S_TopLevelDecl = 37,                     // TopLevelDecl
        S_GlobVarDecl = 38,                      // GlobVarDecl
        S_VarDecl = 39,                          // VarDecl
        S_Type = 40,                             // Type
        S_FuncDecl = 41,                         // FuncDecl
        S_FuncSign = 42,                         // FuncSign
        S_Params = 43,                           // Params
        S_ParamList = 44,                        // ParamList
        S_ParamDecl = 45,                        // ParamDecl
        S_Block = 46,                            // Block
        S_StmtList = 47,                         // StmtList
        S_Stmt = 48,                             // Stmt
        S_SimpleStmt = 49,                       // SimpleStmt
        S_ReturnStmt = 50,                       // ReturnStmt
        S_BreakStmt = 51,                        // BreakStmt
        S_IfStmt = 52,                           // IfStmt
        S_ElseStmt = 53,                         // ElseStmt
        S_ForStmt = 54,                          // ForStmt
        S_EmptyStmt = 55,                        // EmptyStmt
        S_ExprStmt = 56,                         // ExprStmt
        S_AssignStmt = 57,                       // AssignStmt
        S_Expr = 58,                             // Expr
        S_AndExpr = 59,                          // AndExpr
        S_RelExpr = 60,                          // RelExpr
        S_AddExpr = 61,                          // AddExpr
        S_MultExpr = 62,                         // MultExpr
        S_UnaryExpr = 63,                        // UnaryExpr
        S_PrimaryExpr = 64,                      // PrimaryExpr
        S_FuncCall = 65,                         // FuncCall
        S_FuncArgs = 66,                         // FuncArgs
        S_ExprList = 67,                         // ExprList
        S_Operand = 68,                          // Operand
        S_UnaryOp = 69,                          // UnaryOp
        S_RelOp = 70,                            // RelOp
        S_AddOp = 71,                            // AddOp
        S_MultOp = 72                            // MultOp
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
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
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_FuncArgs: // FuncArgs
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
        value.move< std::shared_ptr<AstNode> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AstNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AstNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_FuncArgs: // FuncArgs
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
        value.template destroy< std::shared_ptr<AstNode> > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
     Parser  (Lexer &lexer_yyarg, std::shared_ptr<GoLF::AstNode>& root_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (std::string v, location_type l)
      {
        return symbol_type (token::LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (std::string v, location_type l)
      {
        return symbol_type (token::RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (std::string v, location_type l)
      {
        return symbol_type (token::LBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (std::string v, location_type l)
      {
        return symbol_type (token::RBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v, location_type l)
      {
        return symbol_type (token::AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (std::string v, location_type l)
      {
        return symbol_type (token::EQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQ (std::string v, location_type l)
      {
        return symbol_type (token::NEQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NEQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NEQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (std::string v, location_type l)
      {
        return symbol_type (token::NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v, location_type l)
      {
        return symbol_type (token::OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (std::string v, location_type l)
      {
        return symbol_type (token::LT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LTE (std::string v, location_type l)
      {
        return symbol_type (token::LTE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LTE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LTE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (std::string v, location_type l)
      {
        return symbol_type (token::GT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::GT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GTE (std::string v, location_type l)
      {
        return symbol_type (token::GTE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GTE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::GTE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (std::string v, location_type l)
      {
        return symbol_type (token::ADD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ADD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (std::string v, location_type l)
      {
        return symbol_type (token::SUB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUB (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SUB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (std::string v, location_type l)
      {
        return symbol_type (token::MULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v, location_type l)
      {
        return symbol_type (token::DIV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DIV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (std::string v, location_type l)
      {
        return symbol_type (token::MOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (std::string v, location_type l)
      {
        return symbol_type (token::BREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (std::string v, location_type l)
      {
        return symbol_type (token::FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNC (std::string v, location_type l)
      {
        return symbol_type (token::FUNC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FUNC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FUNC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v, location_type l)
      {
        return symbol_type (token::RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (std::string v, location_type l)
      {
        return symbol_type (token::VAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_LIT (std::string v, location_type l)
      {
        return symbol_type (token::INT_LIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT_LIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INT_LIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STR_LIT (std::string v, location_type l)
      {
        return symbol_type (token::STR_LIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STR_LIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STR_LIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif


    class context
    {
    public:
      context (const  Parser & yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const  Parser & yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 109,     ///< Last index in yytable_.
      yynnts_ = 39,  ///< Number of nonterminal symbols.
      yyfinal_ = 2 ///< Termination state number.
    };


    // User arguments.
    Lexer &lexer;
    std::shared_ptr<GoLF::AstNode>& root;

  };

  inline
   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    // Last valid token kind.
    const int code_max = 288;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
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
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_FuncArgs: // FuncArgs
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
        value.copy< std::shared_ptr<AstNode> > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MultExpr: // MultExpr
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
      case symbol_kind::S_FuncCall: // FuncCall
      case symbol_kind::S_FuncArgs: // FuncArgs
      case symbol_kind::S_ExprList: // ExprList
      case symbol_kind::S_Operand: // Operand
      case symbol_kind::S_UnaryOp: // UnaryOp
      case symbol_kind::S_RelOp: // RelOp
      case symbol_kind::S_AddOp: // AddOp
      case symbol_kind::S_MultOp: // MultOp
        value.move< std::shared_ptr<AstNode> > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
   Parser ::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
   Parser ::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
   Parser ::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
   Parser ::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 31 "src/parse.y"
} //  GoLF 
#line 2203 "src/parse.tab.hh"




#endif // !YY_YY_SRC_PARSE_TAB_HH_INCLUDED
