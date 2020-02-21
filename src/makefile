ECHO=echo
RM=rm
COMP=g++
EDL=g++
INT=main.h symbole.h lexer.h
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o)
EXE=exec

CPPFLAGS=-W -Wall -ansi -pedantic -std=c++11
LDFLAGS=-W -Wall -ansi -pedantic -std=c++11
RMFLAGS=-f
EFFACE=efface

%.o = %.cpp
	$(ECHO) "compil de <$<>"
	$(COMP) -o %.o -c $< $(CPPFLAGS)

$(EXE) : $(OBJ)
	$(ECHO) "Edl de <$<>"
	$(EDL) -o $(EXE) $(OBJ) $(LDFLAGS)

$(EFFACE) :
	$(RM) $(RMFLAGS)