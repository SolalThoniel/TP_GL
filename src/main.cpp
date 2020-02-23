#include <iostream>
#include "automate.h"


int main(void) {
   string chaine;
   cout << "Veuillez entrer l'expression à analyser : ";
   cin >> chaine;

   Lexer l(chaine);
   Automate a(&l);
   Symbole * s;

   while(a.getAccepter() == false) {
      s=l.Consulter();
      a.transition(s);
   }

   cout << "Le resultat est : " << a.evalFin() << endl;

   delete(s);

   return 0;
}

