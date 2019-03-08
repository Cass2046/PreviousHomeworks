lab08: main.o Pokemon.o Executive.o Test.o NotFoundException.o
	g++ -g -std=c++11 -Wall main.o Pokemon.o Executive.o Test.o NotFoundException.o -o lab08
main.o: main.cpp Pokemon.h Pokemon.cpp Executive.h Executive.cpp Test.h Test.cpp NotFoundException.h NotFoundException.cpp BinaryNode.hpp BinaryNode.h BST.hpp BST.h 
	g++ -g -std=c++11 -Wall -c main.cpp
Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -g -std=c++11 -Wall -c Pokemon.cpp
Executive.o: Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp
NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -g -std=c++11 -Wall -c NotFoundException.cpp
clean:
	rm *.o lab08