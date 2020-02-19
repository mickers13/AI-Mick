run: Mastermind.o
	g++ -o run Functions.o Mastermind.o Algorithms.o
	./run

Mastermind.o: Mastermind.cpp
	g++ -c Mastermind.cpp
Functions.o: Functions.cpp
	g++ -c Functions.cpp
Algorithms.o: Algorithms.cpp
	g++ -c Algorithms.cpp
clean:
	rm *.o run.exe
													