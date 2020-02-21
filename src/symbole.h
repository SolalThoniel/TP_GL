#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

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
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr() : Symbole(EXPR, false) {}
      virtual double eval(const map<string, double> &valeurs) = 0;
};

class ExprPlus : public Expr {
   public:
      ExprPlus() : Expr() {}
      virtual double eval(const map<string, double> &valeurs);
};

class ExprMult : public Expr {
   public:
      ExprMult() : Expr() {}
      virtual double eval(const map<string, double> &valeurs);
};

class ExprConst : public Expr {
   public:
      ExprConst() : Expr() {}
      virtual double eval(const map<string, double> &valeurs);

   protected:
      int valeur;
};

