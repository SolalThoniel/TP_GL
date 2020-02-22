#include "etats.h"
#include "lexer.h"
#include <string>
#include <deque>
using namespace std;

class Automate{
	
public:
	Automate(Lexer *l) :  lexer(l) {statestack.push_back(new E0);}
	virtual ~Automate();
	void decalage(Symbole * s, Etat * e);
	void reduction(int n, Symbole * s);
	void transition(Symbole *s);
	Symbole * popSymbol();
	void popAndDestroySymbol();

protected:
	deque<Symbole *> symbolstack;
	deque<Etat *> statestack;
	Lexer * lexer;
};