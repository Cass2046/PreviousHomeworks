lab09: main.o Package.o Executive.o
	g++ -g -std=c++11 -Wall main.o Package.o Executive.o -o lab09
main.o: main.cpp Executive.h Executive.cpp Heap.h Heap.hpp HeapInterface.h
	g++ -g -std=c++11 -Wall -c main.cpp
Package.o: Package.h Package.cpp
	g++ -g -std=c++11 -Wall -c Package.cpp
Executive.o: Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp
clean:
	rm *.o lab09