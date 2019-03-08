lab04: main.o StarWarsShip.o StarTrekShip.o FightManager.o
	g++ -g -std=c++11 main.o StarWarsShip.o StarTrekShip.o FightManager.o -o lab04

main.o: main.cpp FightManager.h
	g++ -g -std=c++11 -c main.cpp

StarWarsShip.o: StarWarsShip.cpp StarWarsShip.h SpaceShipInterface.h
	g++ -g -std=c++11 -c StarWarsShip.cpp

StarTrekShip.o: StarTrekShip.cpp  StarTrekShip.h SpaceShipInterface.h
	g++ -g -std=c++11 -c StarTrekShip.cpp

FightManager.o: FightManager.h FightManager.cpp Node.h LinkedList.h Node.hpp LinkedList.hpp SpaceShipInterface.h StarWarsShip.h StarTrekShip.h
	g++ -g -std=c++11 -c FightManager.cpp

clean:
	rm *.o lab04
