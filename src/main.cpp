#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine;
   cout << "Veuillez entrer l'expression à analyser : ";
   cin >> chaine;

   Lexer l(chaine);
   Automate a(&l);
   Symbole * s;

   while(*(s=l.Consulter())!=FIN) {
      a.transition(s);
      cout<<endl;
      l.Avancer();
   }
   return 0;
}

