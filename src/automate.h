#include "etat.h"
#include "lexer.h"
#include <string>
#include <deque>
using namespace std;

class Automate{
	
public:
	Automate();
	virtual ~Automate();
	void decalage(Symbole * s, Etat * e);
	void reduction(int n, Symbole * s);
	Symbole * popSymbol();
	void popAndDestroySymbol();

protected:
	deque<Symbole *> symbolstack;
	deque<Etat *> statestack;
	Lexer * lexer;
};