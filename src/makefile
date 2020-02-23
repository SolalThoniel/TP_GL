exe=LALR_TP
cpp=main.cpp lexer.cpp symbole.cpp etat.cpp etats.cpp automate.cpp
head=$(cpp:.cpp=.h)
obj=$(head:.h=.o)
comp=g++ -ansi -pedantic -Wall -std=c++11 -g -D MAP
edl=-lm

$(exe) : $(obj)
	g++ -o $(exe) $(obj) $(edl)

%.o : %.cpp %.h
	$(comp) -c $<

clean :
	rm $(obj)
