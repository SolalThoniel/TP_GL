#include "etat.h"

class E0 : public Etat
{
public:
    E0() : Etat("E0") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E1 : public Etat
{
public:
    E1() : Etat("E1") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E2 : public Etat
{
public:
    E2() : Etat("E2") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E3 : public Etat
{
public:
    E3() : Etat("E3") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E4 : public Etat
{
public:
    E4() : Etat("E4") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E5 : public Etat
{
public:
    E5() : Etat("E5") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E6 : public Etat
{
public:
    E6() : Etat("E6") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E7 : public Etat
{
public:
    E7() : Etat("E7") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E8 : public Etat
{
public:
    E8() : Etat("E8") {}
    virtual bool transition(Automate &automate, Symbole *s);
};

class E9 : public Etat
{
public:
    E9() : Etat("E9") {}
    virtual bool transition(Automate &automate, Symbole *s);
};