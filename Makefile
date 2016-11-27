all : calc test

calc : calc.o eval.o
	g++ calc.o eval.o -o calc

test : test.o eval.o
	g++ test.o eval.o -o test

calc.o : calc.cpp
	g++ -c calc.cpp -o calc.o

eval.o : eval.cpp
	g++ -c eval.cpp -o eval.o

test.o : test.cpp
	g++ -c test.cpp -o test.o

PHONY : clean
clean :
	rm -f  calc test *.o





