#include "automate.h"

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
	symbolstack.pop_back();
}