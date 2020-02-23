#include "automate.h"
#include <iostream>

using namespace std;

void Automate::decalage(Symbole * s, Etat * e) {
	symbolstack.push_back(s);
	statestack.push_back(e);
	if (s->isTerminal()) {
		lexer->Avancer();
	}
}

void Automate::reduction(int n, Symbole * s) {
	for (int i=0; i<n; i++)
	{
		delete(statestack.back());
		statestack.pop_back();
	}
	statestack.back()->transition(*this, s);
}

void Automate::transition(Symbole * s)
{
	statestack.back()->transition(*this, s);
}

Symbole * Automate::popSymbol()
{
	Symbole *s = symbolstack.back();
	symbolstack.pop_back();
	return s;
}

void Automate::popAndDestroySymbol()
{
	delete(symbolstack.back());
	symbolstack.pop_back();
}

void Automate::toString()
{
	cout << "Taille pile symboles : " << symbolstack.size() << endl;
	cout << "Taille pile d'état : " << statestack.size() << endl;
	for (int x=0; x < statestack.size(); ++x) {
        statestack[x]->print();
    }
	cout << endl;
}

int Automate::evalFin()
{
	Expr* eFin = (Expr*)symbolstack.back();
	int eval = eFin->eval();
	return eval;
}

void Automate::fin(){
	accepter = true;
}