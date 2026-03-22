#pragma once
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SMLoc.h>
#include <memory>
#include <vector>
class ASTNode {
public:
  virtual ~ASTNode() = default;
};

class Expr;
class Stmt;
class Fact;
class Decl;

class Decl : ASTNode {
public:
  enum DeclType {
    DT_TYPE,
    DT_VAR,
    DT_PROC,
    DT_PARAM,
    DT_CONST,
    DT_MODULE,
  };

private:
  const DeclType Type;

protected:
  Decl *Enclosing_decl;
  llvm::SMLoc Location;
  llvm::StringRef Name;
  Decl(DeclType Type, Decl *EnclosingDecl, llvm::SMLoc Loc,
       llvm::StringRef Name)
      : Type(Type), Enclosing_decl(EnclosingDecl), Location(Loc), Name(Name) {}

  DeclType getKind() const { return Type; }
  llvm::SMLoc getLocation() { return Location; }
  llvm::StringRef getName() { return Name; }
  Decl *getEnclosingDecl() { return Enclosing_decl; }
};

class ModuleDecl : Decl {
  std::vector<std::unique_ptr<Decl>> DeclArr;
  std::vector<std::unique_ptr<Stmt>> StmtArr;

  ModuleDecl(Decl *EnclosingDecl, llvm::SMLoc Loc, llvm::StringRef Name)
      : Decl(DT_MODULE, EnclosingDecl, Loc, Name) {}
};

class TypeDecl : Decl {
  TypeDecl(Decl *EnclosingDecl, llvm::SMLoc Loc, llvm::StringRef Name)
      : Decl(DT_TYPE, EnclosingDecl, Loc, Name) {}
};

class VarDecl : Decl {
  TypeDecl *Type_decl;
  VarDecl(Decl *EnclosingDecl, llvm::SMLoc Loc, llvm::StringRef Name,
          TypeDecl *type_decl)
      : Decl(DT_VAR, EnclosingDecl, Loc, Name), Type_decl(type_decl) {}

  TypeDecl *getType() { return Type_decl; }
};
class ParamDecl : Decl {
  TypeDecl *Type_decl;
  ParamDecl(Decl *EnclosingDecl, llvm::SMLoc Loc, llvm::StringRef Name,
            TypeDecl *type_decl)
      : Decl(DT_PARAM, EnclosingDecl, Loc, Name), Type_decl(type_decl) {}

  TypeDecl *getType() { return Type_decl; }
};

class ProcDecl : Decl {
  TypeDecl *Return_type;
  std::vector<Decl> Decl_arr;
  std::vector<Stmt> Stmt_arr;
  std::vector<ParamDecl> param_arr;
  ProcDecl(Decl *EnclosingDecl, llvm::SMLoc Loc, llvm::StringRef Name,
           TypeDecl *Return_type)
      : Decl(DT_PROC, EnclosingDecl, Loc, Name), Return_type(Return_type) {}
};

class Expr : ASTNode {
public:
  enum ExprType{
	
  };
};
