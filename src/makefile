exe=LALR_TP
cpp=main.cpp lexer.cpp symbole.cpp etat.cpp automate.cpp
head=$(cpp:.cpp=.h)
obj=$(head:.h=.o)
comp=g++ -ansi -pedantic -Wall -std=c++11 -g -D MAP
edl=-lm

$(exe) : $(obj)
	g++ -o $(exe) $(obj) $(edl)

%.o : %.cpp %.h
	$(comp) -c $<

main.o : main.cpp
lexer.o : lexer.cpp lexer.h
symbole.o : symbole.cpp symbole.h
etat.o : etat.cpp automate.h
etats.o : etats.cpp etats.h automate.h
automate.o : automate.cpp automate.h etat.h

clean :
	rm $(obj)
