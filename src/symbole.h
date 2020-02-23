#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole {
   public:
      Symbole(int i, bool term) : ident(i), terminal(term) {  }
      virtual ~Symbole() { }
      virtual void Affiche();
      bool isTerminal() { return terminal; }
      operator int() const { return ident; }

   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT, true), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getVal() {return valeur;}
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr() : Symbole(EXPR, false) {}
      virtual ~Expr() {};
      virtual int eval() = 0;
};

class ExprPlus : public Expr {
   public:
      ExprPlus(Expr *e1, Expr *e2) : Expr(), expr1(e1), expr2(e2) {}
      virtual ~ExprPlus() 
      {
         if(expr1 != nullptr)
         {
            delete(expr1);
         }
         if(expr2 != nullptr)
         {
            delete(expr2);
         }
      }
      int eval() {return expr1->eval()+expr2->eval();}
   protected:
      Expr *expr1;
      Expr *expr2;

};

class ExprMult : public Expr {
   public:
      ExprMult(Expr *e1, Expr *e2) : Expr(), expr1(e1), expr2(e2) {}
      virtual ~ExprMult() 
      {
         if(expr1 != nullptr)
         {
            delete(expr1);
         }
         if(expr2 != nullptr)
         {
            delete(expr2);
         }
      }
      int eval() {return expr1->eval()*expr2->eval();}
   protected:
      Expr *expr1;
      Expr *expr2;
};

class ExprConst : public Expr {
   public:
      ExprConst(Entier *en) : Expr(), entier(en) {}
      virtual ~ExprConst() 
      {
         if(entier != nullptr)
         {
            delete(entier);
         }
      }
      int eval() {return entier->getVal();}
   protected:
      Entier *entier;
};