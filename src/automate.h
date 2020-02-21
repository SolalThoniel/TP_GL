#include "etat.h"
#include <string>
using namespace std;

class Automate{
	
public:
	Automate();
	virtual ~Automate();
	void decalage(Symbole * s, Etat * e);
	void reduction(int n,Symbole * s);
	
	
};