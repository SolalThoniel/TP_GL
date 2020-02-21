#include "etat.h"

class E0 : public Etat {
	E0() : Etat("E0"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E1 : public Etat {
	E1() : Etat("E1"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E2 : public Etat {
	E2() : Etat("E2"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E3 : public Etat {
	E3() : Etat("E3"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E4 : public Etat {
	E4() : Etat("E4"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E5 : public Etat {
	E5() : Etat("E5"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E6 : public Etat {
	E6() : Etat("E6"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E7 : public Etat {
	E7() : Etat("E7"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E8 : public Etat {
	E8() : Etat("E8"){}
    virtual bool transition(Automate & automate, Symbole * s);
};

class E9 : public Etat {
	E9() : Etat("E9"){}
    virtual bool transition(Automate & automate, Symbole * s);
};