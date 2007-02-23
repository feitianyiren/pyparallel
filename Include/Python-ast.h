/* File automatically generated by Parser/asdl_c.py. */

#include "asdl.h"

typedef struct _mod *mod_ty;

typedef struct _stmt *stmt_ty;

typedef struct _expr *expr_ty;

typedef enum _expr_context { Load=1, Store=2, Del=3, AugLoad=4, AugStore=5,
                             Param=6 } expr_context_ty;

typedef struct _slice *slice_ty;

typedef enum _boolop { And=1, Or=2 } boolop_ty;

typedef enum _operator { Add=1, Sub=2, Mult=3, Div=4, Mod=5, Pow=6, LShift=7,
                         RShift=8, BitOr=9, BitXor=10, BitAnd=11, FloorDiv=12 }
                         operator_ty;

typedef enum _unaryop { Invert=1, Not=2, UAdd=3, USub=4 } unaryop_ty;

typedef enum _cmpop { Eq=1, NotEq=2, Lt=3, LtE=4, Gt=5, GtE=6, Is=7, IsNot=8,
                      In=9, NotIn=10 } cmpop_ty;

typedef struct _comprehension *comprehension_ty;

typedef struct _excepthandler *excepthandler_ty;

typedef struct _arguments *arguments_ty;

typedef struct _arg *arg_ty;

typedef struct _keyword *keyword_ty;

typedef struct _alias *alias_ty;


enum _mod_kind {Module_kind=1, Interactive_kind=2, Expression_kind=3,
                 Suite_kind=4};
struct _mod {
        enum _mod_kind kind;
        union {
                struct {
                        asdl_seq *body;
                } Module;
                
                struct {
                        asdl_seq *body;
                } Interactive;
                
                struct {
                        expr_ty body;
                } Expression;
                
                struct {
                        asdl_seq *body;
                } Suite;
                
        } v;
};

enum _stmt_kind {FunctionDef_kind=1, ClassDef_kind=2, Return_kind=3,
                  Delete_kind=4, Assign_kind=5, AugAssign_kind=6, For_kind=7,
                  While_kind=8, If_kind=9, With_kind=10, Raise_kind=11,
                  TryExcept_kind=12, TryFinally_kind=13, Assert_kind=14,
                  Import_kind=15, ImportFrom_kind=16, Global_kind=17,
                  Expr_kind=18, Pass_kind=19, Break_kind=20, Continue_kind=21};
struct _stmt {
        enum _stmt_kind kind;
        union {
                struct {
                        identifier name;
                        arguments_ty args;
                        asdl_seq *body;
                        asdl_seq *decorators;
                        expr_ty returns;
                } FunctionDef;
                
                struct {
                        identifier name;
                        asdl_seq *bases;
                        asdl_seq *body;
                } ClassDef;
                
                struct {
                        expr_ty value;
                } Return;
                
                struct {
                        asdl_seq *targets;
                } Delete;
                
                struct {
                        asdl_seq *targets;
                        expr_ty value;
                } Assign;
                
                struct {
                        expr_ty target;
                        operator_ty op;
                        expr_ty value;
                } AugAssign;
                
                struct {
                        expr_ty target;
                        expr_ty iter;
                        asdl_seq *body;
                        asdl_seq *orelse;
                } For;
                
                struct {
                        expr_ty test;
                        asdl_seq *body;
                        asdl_seq *orelse;
                } While;
                
                struct {
                        expr_ty test;
                        asdl_seq *body;
                        asdl_seq *orelse;
                } If;
                
                struct {
                        expr_ty context_expr;
                        expr_ty optional_vars;
                        asdl_seq *body;
                } With;
                
                struct {
                        expr_ty type;
                        expr_ty inst;
                        expr_ty tback;
                } Raise;
                
                struct {
                        asdl_seq *body;
                        asdl_seq *handlers;
                        asdl_seq *orelse;
                } TryExcept;
                
                struct {
                        asdl_seq *body;
                        asdl_seq *finalbody;
                } TryFinally;
                
                struct {
                        expr_ty test;
                        expr_ty msg;
                } Assert;
                
                struct {
                        asdl_seq *names;
                } Import;
                
                struct {
                        identifier module;
                        asdl_seq *names;
                        int level;
                } ImportFrom;
                
                struct {
                        asdl_seq *names;
                } Global;
                
                struct {
                        expr_ty value;
                } Expr;
                
        } v;
        int lineno;
        int col_offset;
};

enum _expr_kind {BoolOp_kind=1, BinOp_kind=2, UnaryOp_kind=3, Lambda_kind=4,
                  IfExp_kind=5, Dict_kind=6, Set_kind=7, ListComp_kind=8,
                  GeneratorExp_kind=9, Yield_kind=10, Compare_kind=11,
                  Call_kind=12, Num_kind=13, Str_kind=14, Ellipsis_kind=15,
                  Attribute_kind=16, Subscript_kind=17, Name_kind=18,
                  List_kind=19, Tuple_kind=20};
struct _expr {
        enum _expr_kind kind;
        union {
                struct {
                        boolop_ty op;
                        asdl_seq *values;
                } BoolOp;
                
                struct {
                        expr_ty left;
                        operator_ty op;
                        expr_ty right;
                } BinOp;
                
                struct {
                        unaryop_ty op;
                        expr_ty operand;
                } UnaryOp;
                
                struct {
                        arguments_ty args;
                        expr_ty body;
                } Lambda;
                
                struct {
                        expr_ty test;
                        expr_ty body;
                        expr_ty orelse;
                } IfExp;
                
                struct {
                        asdl_seq *keys;
                        asdl_seq *values;
                } Dict;
                
                struct {
                        asdl_seq *elts;
                } Set;
                
                struct {
                        expr_ty elt;
                        asdl_seq *generators;
                } ListComp;
                
                struct {
                        expr_ty elt;
                        asdl_seq *generators;
                } GeneratorExp;
                
                struct {
                        expr_ty value;
                } Yield;
                
                struct {
                        expr_ty left;
                        asdl_int_seq *ops;
                        asdl_seq *comparators;
                } Compare;
                
                struct {
                        expr_ty func;
                        asdl_seq *args;
                        asdl_seq *keywords;
                        expr_ty starargs;
                        expr_ty kwargs;
                } Call;
                
                struct {
                        object n;
                } Num;
                
                struct {
                        string s;
                } Str;
                
                struct {
                        expr_ty value;
                        identifier attr;
                        expr_context_ty ctx;
                } Attribute;
                
                struct {
                        expr_ty value;
                        slice_ty slice;
                        expr_context_ty ctx;
                } Subscript;
                
                struct {
                        identifier id;
                        expr_context_ty ctx;
                } Name;
                
                struct {
                        asdl_seq *elts;
                        expr_context_ty ctx;
                } List;
                
                struct {
                        asdl_seq *elts;
                        expr_context_ty ctx;
                } Tuple;
                
        } v;
        int lineno;
        int col_offset;
};

enum _slice_kind {Slice_kind=1, ExtSlice_kind=2, Index_kind=3};
struct _slice {
        enum _slice_kind kind;
        union {
                struct {
                        expr_ty lower;
                        expr_ty upper;
                        expr_ty step;
                } Slice;
                
                struct {
                        asdl_seq *dims;
                } ExtSlice;
                
                struct {
                        expr_ty value;
                } Index;
                
        } v;
};

struct _comprehension {
        expr_ty target;
        expr_ty iter;
        asdl_seq *ifs;
};

struct _excepthandler {
        expr_ty type;
        identifier name;
        asdl_seq *body;
        int lineno;
        int col_offset;
};

struct _arguments {
        asdl_seq *args;
        identifier vararg;
        expr_ty varargannotation;
        asdl_seq *kwonlyargs;
        identifier kwarg;
        expr_ty kwargannotation;
        asdl_seq *defaults;
        asdl_seq *kw_defaults;
};

enum _arg_kind {SimpleArg_kind=1, NestedArgs_kind=2};
struct _arg {
        enum _arg_kind kind;
        union {
                struct {
                        identifier arg;
                        expr_ty annotation;
                } SimpleArg;
                
                struct {
                        asdl_seq *args;
                } NestedArgs;
                
        } v;
};

struct _keyword {
        identifier arg;
        expr_ty value;
};

struct _alias {
        identifier name;
        identifier asname;
};


#define Module(a0, a1) _Py_Module(a0, a1)
mod_ty _Py_Module(asdl_seq * body, PyArena *arena);
#define Interactive(a0, a1) _Py_Interactive(a0, a1)
mod_ty _Py_Interactive(asdl_seq * body, PyArena *arena);
#define Expression(a0, a1) _Py_Expression(a0, a1)
mod_ty _Py_Expression(expr_ty body, PyArena *arena);
#define Suite(a0, a1) _Py_Suite(a0, a1)
mod_ty _Py_Suite(asdl_seq * body, PyArena *arena);
#define FunctionDef(a0, a1, a2, a3, a4, a5, a6, a7) _Py_FunctionDef(a0, a1, a2, a3, a4, a5, a6, a7)
stmt_ty _Py_FunctionDef(identifier name, arguments_ty args, asdl_seq * body,
                        asdl_seq * decorators, expr_ty returns, int lineno, int
                        col_offset, PyArena *arena);
#define ClassDef(a0, a1, a2, a3, a4, a5) _Py_ClassDef(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_ClassDef(identifier name, asdl_seq * bases, asdl_seq * body, int
                     lineno, int col_offset, PyArena *arena);
#define Return(a0, a1, a2, a3) _Py_Return(a0, a1, a2, a3)
stmt_ty _Py_Return(expr_ty value, int lineno, int col_offset, PyArena *arena);
#define Delete(a0, a1, a2, a3) _Py_Delete(a0, a1, a2, a3)
stmt_ty _Py_Delete(asdl_seq * targets, int lineno, int col_offset, PyArena
                   *arena);
#define Assign(a0, a1, a2, a3, a4) _Py_Assign(a0, a1, a2, a3, a4)
stmt_ty _Py_Assign(asdl_seq * targets, expr_ty value, int lineno, int
                   col_offset, PyArena *arena);
#define AugAssign(a0, a1, a2, a3, a4, a5) _Py_AugAssign(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_AugAssign(expr_ty target, operator_ty op, expr_ty value, int
                      lineno, int col_offset, PyArena *arena);
#define For(a0, a1, a2, a3, a4, a5, a6) _Py_For(a0, a1, a2, a3, a4, a5, a6)
stmt_ty _Py_For(expr_ty target, expr_ty iter, asdl_seq * body, asdl_seq *
                orelse, int lineno, int col_offset, PyArena *arena);
#define While(a0, a1, a2, a3, a4, a5) _Py_While(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_While(expr_ty test, asdl_seq * body, asdl_seq * orelse, int lineno,
                  int col_offset, PyArena *arena);
#define If(a0, a1, a2, a3, a4, a5) _Py_If(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_If(expr_ty test, asdl_seq * body, asdl_seq * orelse, int lineno,
               int col_offset, PyArena *arena);
#define With(a0, a1, a2, a3, a4, a5) _Py_With(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_With(expr_ty context_expr, expr_ty optional_vars, asdl_seq * body,
                 int lineno, int col_offset, PyArena *arena);
#define Raise(a0, a1, a2, a3, a4, a5) _Py_Raise(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_Raise(expr_ty type, expr_ty inst, expr_ty tback, int lineno, int
                  col_offset, PyArena *arena);
#define TryExcept(a0, a1, a2, a3, a4, a5) _Py_TryExcept(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_TryExcept(asdl_seq * body, asdl_seq * handlers, asdl_seq * orelse,
                      int lineno, int col_offset, PyArena *arena);
#define TryFinally(a0, a1, a2, a3, a4) _Py_TryFinally(a0, a1, a2, a3, a4)
stmt_ty _Py_TryFinally(asdl_seq * body, asdl_seq * finalbody, int lineno, int
                       col_offset, PyArena *arena);
#define Assert(a0, a1, a2, a3, a4) _Py_Assert(a0, a1, a2, a3, a4)
stmt_ty _Py_Assert(expr_ty test, expr_ty msg, int lineno, int col_offset,
                   PyArena *arena);
#define Import(a0, a1, a2, a3) _Py_Import(a0, a1, a2, a3)
stmt_ty _Py_Import(asdl_seq * names, int lineno, int col_offset, PyArena
                   *arena);
#define ImportFrom(a0, a1, a2, a3, a4, a5) _Py_ImportFrom(a0, a1, a2, a3, a4, a5)
stmt_ty _Py_ImportFrom(identifier module, asdl_seq * names, int level, int
                       lineno, int col_offset, PyArena *arena);
#define Global(a0, a1, a2, a3) _Py_Global(a0, a1, a2, a3)
stmt_ty _Py_Global(asdl_seq * names, int lineno, int col_offset, PyArena
                   *arena);
#define Expr(a0, a1, a2, a3) _Py_Expr(a0, a1, a2, a3)
stmt_ty _Py_Expr(expr_ty value, int lineno, int col_offset, PyArena *arena);
#define Pass(a0, a1, a2) _Py_Pass(a0, a1, a2)
stmt_ty _Py_Pass(int lineno, int col_offset, PyArena *arena);
#define Break(a0, a1, a2) _Py_Break(a0, a1, a2)
stmt_ty _Py_Break(int lineno, int col_offset, PyArena *arena);
#define Continue(a0, a1, a2) _Py_Continue(a0, a1, a2)
stmt_ty _Py_Continue(int lineno, int col_offset, PyArena *arena);
#define BoolOp(a0, a1, a2, a3, a4) _Py_BoolOp(a0, a1, a2, a3, a4)
expr_ty _Py_BoolOp(boolop_ty op, asdl_seq * values, int lineno, int col_offset,
                   PyArena *arena);
#define BinOp(a0, a1, a2, a3, a4, a5) _Py_BinOp(a0, a1, a2, a3, a4, a5)
expr_ty _Py_BinOp(expr_ty left, operator_ty op, expr_ty right, int lineno, int
                  col_offset, PyArena *arena);
#define UnaryOp(a0, a1, a2, a3, a4) _Py_UnaryOp(a0, a1, a2, a3, a4)
expr_ty _Py_UnaryOp(unaryop_ty op, expr_ty operand, int lineno, int col_offset,
                    PyArena *arena);
#define Lambda(a0, a1, a2, a3, a4) _Py_Lambda(a0, a1, a2, a3, a4)
expr_ty _Py_Lambda(arguments_ty args, expr_ty body, int lineno, int col_offset,
                   PyArena *arena);
#define IfExp(a0, a1, a2, a3, a4, a5) _Py_IfExp(a0, a1, a2, a3, a4, a5)
expr_ty _Py_IfExp(expr_ty test, expr_ty body, expr_ty orelse, int lineno, int
                  col_offset, PyArena *arena);
#define Dict(a0, a1, a2, a3, a4) _Py_Dict(a0, a1, a2, a3, a4)
expr_ty _Py_Dict(asdl_seq * keys, asdl_seq * values, int lineno, int
                 col_offset, PyArena *arena);
#define Set(a0, a1, a2, a3) _Py_Set(a0, a1, a2, a3)
expr_ty _Py_Set(asdl_seq * elts, int lineno, int col_offset, PyArena *arena);
#define ListComp(a0, a1, a2, a3, a4) _Py_ListComp(a0, a1, a2, a3, a4)
expr_ty _Py_ListComp(expr_ty elt, asdl_seq * generators, int lineno, int
                     col_offset, PyArena *arena);
#define GeneratorExp(a0, a1, a2, a3, a4) _Py_GeneratorExp(a0, a1, a2, a3, a4)
expr_ty _Py_GeneratorExp(expr_ty elt, asdl_seq * generators, int lineno, int
                         col_offset, PyArena *arena);
#define Yield(a0, a1, a2, a3) _Py_Yield(a0, a1, a2, a3)
expr_ty _Py_Yield(expr_ty value, int lineno, int col_offset, PyArena *arena);
#define Compare(a0, a1, a2, a3, a4, a5) _Py_Compare(a0, a1, a2, a3, a4, a5)
expr_ty _Py_Compare(expr_ty left, asdl_int_seq * ops, asdl_seq * comparators,
                    int lineno, int col_offset, PyArena *arena);
#define Call(a0, a1, a2, a3, a4, a5, a6, a7) _Py_Call(a0, a1, a2, a3, a4, a5, a6, a7)
expr_ty _Py_Call(expr_ty func, asdl_seq * args, asdl_seq * keywords, expr_ty
                 starargs, expr_ty kwargs, int lineno, int col_offset, PyArena
                 *arena);
#define Num(a0, a1, a2, a3) _Py_Num(a0, a1, a2, a3)
expr_ty _Py_Num(object n, int lineno, int col_offset, PyArena *arena);
#define Str(a0, a1, a2, a3) _Py_Str(a0, a1, a2, a3)
expr_ty _Py_Str(string s, int lineno, int col_offset, PyArena *arena);
#define Ellipsis(a0, a1, a2) _Py_Ellipsis(a0, a1, a2)
expr_ty _Py_Ellipsis(int lineno, int col_offset, PyArena *arena);
#define Attribute(a0, a1, a2, a3, a4, a5) _Py_Attribute(a0, a1, a2, a3, a4, a5)
expr_ty _Py_Attribute(expr_ty value, identifier attr, expr_context_ty ctx, int
                      lineno, int col_offset, PyArena *arena);
#define Subscript(a0, a1, a2, a3, a4, a5) _Py_Subscript(a0, a1, a2, a3, a4, a5)
expr_ty _Py_Subscript(expr_ty value, slice_ty slice, expr_context_ty ctx, int
                      lineno, int col_offset, PyArena *arena);
#define Name(a0, a1, a2, a3, a4) _Py_Name(a0, a1, a2, a3, a4)
expr_ty _Py_Name(identifier id, expr_context_ty ctx, int lineno, int
                 col_offset, PyArena *arena);
#define List(a0, a1, a2, a3, a4) _Py_List(a0, a1, a2, a3, a4)
expr_ty _Py_List(asdl_seq * elts, expr_context_ty ctx, int lineno, int
                 col_offset, PyArena *arena);
#define Tuple(a0, a1, a2, a3, a4) _Py_Tuple(a0, a1, a2, a3, a4)
expr_ty _Py_Tuple(asdl_seq * elts, expr_context_ty ctx, int lineno, int
                  col_offset, PyArena *arena);
#define Slice(a0, a1, a2, a3) _Py_Slice(a0, a1, a2, a3)
slice_ty _Py_Slice(expr_ty lower, expr_ty upper, expr_ty step, PyArena *arena);
#define ExtSlice(a0, a1) _Py_ExtSlice(a0, a1)
slice_ty _Py_ExtSlice(asdl_seq * dims, PyArena *arena);
#define Index(a0, a1) _Py_Index(a0, a1)
slice_ty _Py_Index(expr_ty value, PyArena *arena);
#define comprehension(a0, a1, a2, a3) _Py_comprehension(a0, a1, a2, a3)
comprehension_ty _Py_comprehension(expr_ty target, expr_ty iter, asdl_seq *
                                   ifs, PyArena *arena);
#define excepthandler(a0, a1, a2, a3, a4, a5) _Py_excepthandler(a0, a1, a2, a3, a4, a5)
excepthandler_ty _Py_excepthandler(expr_ty type, identifier name, asdl_seq *
                                   body, int lineno, int col_offset, PyArena
                                   *arena);
#define arguments(a0, a1, a2, a3, a4, a5, a6, a7, a8) _Py_arguments(a0, a1, a2, a3, a4, a5, a6, a7, a8)
arguments_ty _Py_arguments(asdl_seq * args, identifier vararg, expr_ty
                           varargannotation, asdl_seq * kwonlyargs, identifier
                           kwarg, expr_ty kwargannotation, asdl_seq * defaults,
                           asdl_seq * kw_defaults, PyArena *arena);
#define SimpleArg(a0, a1, a2) _Py_SimpleArg(a0, a1, a2)
arg_ty _Py_SimpleArg(identifier arg, expr_ty annotation, PyArena *arena);
#define NestedArgs(a0, a1) _Py_NestedArgs(a0, a1)
arg_ty _Py_NestedArgs(asdl_seq * args, PyArena *arena);
#define keyword(a0, a1, a2) _Py_keyword(a0, a1, a2)
keyword_ty _Py_keyword(identifier arg, expr_ty value, PyArena *arena);
#define alias(a0, a1, a2) _Py_alias(a0, a1, a2)
alias_ty _Py_alias(identifier name, identifier asname, PyArena *arena);

PyObject* PyAST_mod2obj(mod_ty t);
