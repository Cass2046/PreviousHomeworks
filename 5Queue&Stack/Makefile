lab05: main.o Executive.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o Executive.o PreconditionViolationException.o -o lab05

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Queue.h Queue.hpp QueueInterface.h Stack.h Stack.hpp StackInterface.h Node.h Node.hpp PreconditionViolationException.h
	g++ -g -std=c++11 -c Executive.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

clean:
	rm *.o lab05