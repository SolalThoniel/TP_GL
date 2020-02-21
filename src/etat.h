#include "symbole.h"
class Automate;

class Etat {
	
public:
	Etat(string name) : name(name) {}
	virtual ~Etat();
	void print() const;
	virtual bool transition(Automate & automate, Symbole * s) = 0;
	
protected:
	string name;
};