#ifndef YY_Calculator_h_included
#define YY_Calculator_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_Calculator_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_Calculator_COMPATIBILITY 1
 #else
  #define  YY_Calculator_COMPATIBILITY 0
 #endif
#endif

#if YY_Calculator_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_Calculator_LTYPE
   #define YY_Calculator_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_Calculator_STYPE
   #define YY_Calculator_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_Calculator_DEBUG
   #define  YY_Calculator_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_Calculator_USE_GOTO
  #define YY_Calculator_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_Calculator_USE_GOTO
 #define YY_Calculator_USE_GOTO 0
#endif

#ifndef YY_Calculator_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_Calculator_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"
#ifndef YY_USE_CLASS
# ifndef YYSTYPE
#  define YYSTYPE int
#  define YYSTYPE_IS_TRIVIAL 1
# endif
#endif

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_Calculator_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_Calculator_DEBUG */
#endif

#ifndef YY_Calculator_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_Calculator_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_Calculator_LSP_NEEDED
 #ifndef YY_Calculator_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_Calculator_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_Calculator_STYPE
 #define YY_Calculator_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_Calculator_PARSE
 #define YY_Calculator_PARSE yyparse
#endif

#ifndef YY_Calculator_LEX
 #define YY_Calculator_LEX yylex
#endif

#ifndef YY_Calculator_LVAL
 #define YY_Calculator_LVAL yylval
#endif

#ifndef YY_Calculator_LLOC
 #define YY_Calculator_LLOC yylloc
#endif

#ifndef YY_Calculator_CHAR
 #define YY_Calculator_CHAR yychar
#endif

#ifndef YY_Calculator_NERRS
 #define YY_Calculator_NERRS yynerrs
#endif

#ifndef YY_Calculator_DEBUG_FLAG
 #define YY_Calculator_DEBUG_FLAG yydebug
#endif

#ifndef YY_Calculator_ERROR
 #define YY_Calculator_ERROR yyerror
#endif

#ifndef YY_Calculator_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_Calculator_PARSE_PARAM
    #ifndef YY_Calculator_PARSE_PARAM_DEF
     #define YY_Calculator_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_Calculator_PARSE_PARAM
  #define YY_Calculator_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_Calculator_PURE
  #ifndef yylval
   extern YY_Calculator_STYPE YY_Calculator_LVAL;
  #else
   #if yylval != YY_Calculator_LVAL
    extern YY_Calculator_STYPE YY_Calculator_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	NUMBER	258
#define	ALPHA	259


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_Calculator_CLASS
  #define YY_Calculator_CLASS Calculator
 #endif

 #ifndef YY_Calculator_INHERIT
  #define YY_Calculator_INHERIT
 #endif

 #ifndef YY_Calculator_MEMBERS
  #define YY_Calculator_MEMBERS 
 #endif

 #ifndef YY_Calculator_LEX_BODY
  #define YY_Calculator_LEX_BODY  
 #endif

 #ifndef YY_Calculator_ERROR_BODY
  #define YY_Calculator_ERROR_BODY  
 #endif

 #ifndef YY_Calculator_CONSTRUCTOR_PARAM
  #define YY_Calculator_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_Calculator_USE_CONST_TOKEN
  #define YY_Calculator_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_Calculator_USE_CONST_TOKEN != 0
  #ifndef YY_Calculator_ENUM_TOKEN
   #define YY_Calculator_ENUM_TOKEN yy_Calculator_enum_token
  #endif
 #endif

class YY_Calculator_CLASS YY_Calculator_INHERIT
{
public: 
 #if YY_Calculator_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int NUMBER;
static const int ALPHA;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_Calculator_ENUM_TOKEN { YY_Calculator_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,NUMBER=258
	,ALPHA=259


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_Calculator_PARSE(YY_Calculator_PARSE_PARAM);
 virtual void YY_Calculator_ERROR(char *msg) YY_Calculator_ERROR_BODY;
 #ifdef YY_Calculator_PURE
  #ifdef YY_Calculator_LSP_NEEDED
   virtual int  YY_Calculator_LEX(YY_Calculator_STYPE *YY_Calculator_LVAL,YY_Calculator_LTYPE *YY_Calculator_LLOC) YY_Calculator_LEX_BODY;
  #else
   virtual int  YY_Calculator_LEX(YY_Calculator_STYPE *YY_Calculator_LVAL) YY_Calculator_LEX_BODY;
  #endif
 #else
  virtual int YY_Calculator_LEX() YY_Calculator_LEX_BODY;
  YY_Calculator_STYPE YY_Calculator_LVAL;
  #ifdef YY_Calculator_LSP_NEEDED
   YY_Calculator_LTYPE YY_Calculator_LLOC;
  #endif
  int YY_Calculator_NERRS;
  int YY_Calculator_CHAR;
 #endif
 #if YY_Calculator_DEBUG != 0
  public:
   int YY_Calculator_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_Calculator_CLASS(YY_Calculator_CONSTRUCTOR_PARAM);
public:
 YY_Calculator_MEMBERS 
};
/* other declare folow */
#endif


#if YY_Calculator_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_Calculator_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_Calculator_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_Calculator_DEBUG 
   #define YYDEBUG YY_Calculator_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
