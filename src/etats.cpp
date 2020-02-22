#include "etats.h"
#include "automate.h"

bool E0::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
		automate.decalage(s, new E3);
		break;
	case OPENPAR:
		automate.decalage(s, new E2);
		break;
	case EXPR:
		automate.decalage(s, new E1);
		break;
	}

	return false;
}

bool E1::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case PLUS:
		automate.decalage(s, new E4);
		break;
	case MULT:
		automate.decalage(s, new E5);
		break;
	case FIN:
	}

	return false;
}

bool E2::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
		automate.decalage(s, new E3);
		break;
	case OPENPAR:
		automate.decalage(s, new E2);
		break;
	case EXPR:
		automate.decalage(s, new E6);
		break;
	}

	return false;
}

bool E3::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
	case OPENPAR:
	case EXPR:
	default:
		Entier *en1 = (Entier *)automate.popSymbol();
		automate.reduction(1, new ExprConst(en1));
		break;
	}

	return false;
}

bool E4::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
		automate.decalage(s, new E3);
		break;
	case OPENPAR:
		automate.decalage(s, new E2);
		break;
	case EXPR:
		automate.decalage(s, new E7);
		break;
	}

	return false;
}

bool E5::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
		automate.decalage(s, new E3);
		break;
	case OPENPAR:
		automate.decalage(s, new E2);
		break;
	case EXPR:
		automate.decalage(s, new E8);
		break;
	}

	return false;
}

bool E6::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case PLUS:
		automate.decalage(s, new E4);
		break;
	case MULT:
		automate.decalage(s, new E5);
		break;
	case CLOSEPAR:
		automate.decalage(s, new E9);
		break;
	}

	return false;
}

bool E7::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
	case OPENPAR:
	case EXPR:
	case MULT:
		automate.decalage(s, new E5);
		break;
	default:
		Expr *e1 = (Expr *)automate.popSymbol();
		automate.popAndDestroySymbol();
		Expr *e2 = (Expr *)automate.popSymbol();
		automate.reduction(3, new ExprPlus(e2, e1));
		break;
	}

	return false;
}

bool E8::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
	case OPENPAR:
	case EXPR:
	default:
		Expr *e1 = (Expr *)automate.popSymbol();
		automate.popAndDestroySymbol();
		Expr *e2 = (Expr *)automate.popSymbol();
		automate.reduction(3, new ExprMult(e2, e1));
		break;
	}

	return false;
}

bool E9::transition(Automate &automate, Symbole *s)
{

	switch (*s)
	{
	case INT:
	case OPENPAR:
	case EXPR:
	default:
		automate.popAndDestroySymbol();
		Expr *e1 = (Expr *)automate.popSymbol();
		automate.popAndDestroySymbol();
		automate.reduction(3, e1);
		break;
	}

	return false;
}