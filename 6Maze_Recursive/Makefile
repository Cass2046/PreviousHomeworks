lab06: main.o Executive.o MazeCreationException.o MazeReader.o MazeRunner.o
	g++ -g -std=c++11 -Wall main.o Executive.o MazeCreationException.o MazeReader.o MazeRunner.o -o lab06

main.o: main.cpp Executive.h Executive.cpp MazeCreationException.h MazeCreationException.cpp MazeReader.h MazeReader.cpp MazeRunner.h MazeRunner.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp 
	g++ -g -std=c++11 -Wall -c Executive.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -Wall -c MazeCreationException.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -Wall -c MazeReader.cpp

MazeRunner.o: MazeRunner.h MazeRunner.cpp
	g++ -g -std=c++11 -Wall -c MazeRunner.cpp
	
clean:
	rm *.o lab06