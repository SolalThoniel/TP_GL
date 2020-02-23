#include "lexer.h"
#include "etats.h"
#include <string>
#include <deque>
#include <iostream>
using namespace std;

class Automate{
	
public:
	Automate(Lexer *l) :  lexer(l), accepter(false) {statestack.push_back(new E0);}
	virtual ~Automate()
	{
		for(int i = 0; i<symbolstack.size(); i++)
		{
			delete(symbolstack[i]);
		}
		for(int i = 0; i<statestack.size(); i++)
		{
			delete(statestack[i]);
		}
	};
	void toString();
	void decalage(Symbole * s, Etat * e);
	void reduction(int n, Symbole * s);
	void transition(Symbole *s);
	Symbole * popSymbol();
	void popAndDestroySymbol();
	int evalFin();
	void fin();
	bool getAccepter() {return accepter;}

protected:
	deque<Symbole *> symbolstack;
	deque<Etat *> statestack;
	Lexer * lexer;
	bool accepter;
};