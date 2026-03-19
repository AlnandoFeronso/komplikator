#pragma once
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SMLoc.h>
#include <memory>
class AST {};
class Expr {};
class Declaration;
class Stmt;

class Declaration {
public:
  enum DeclarationType {
    Module,
    Const,
    Var,
    Typedef,
    Param,
    Proc,
  };
  const DeclarationType Type;

protected:
  Declaration *EnclosingDeclaration;
  llvm::SMLoc Location;
  llvm::StringRef Name;

public:
  Declaration(DeclarationType Type, Declaration *Enclosing, llvm::SMLoc Loc,
              llvm::StringRef Name)
      : Type(Type), Location(Loc), Name(Name), EnclosingDeclaration(Enclosing){}
};

class ModuleDeclaration {};
