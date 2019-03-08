lab03: main.o City.o MedicalExecutive.o
	g++ -g -std=c++11 main.o City.o MedicalExecutive.o -o lab03

main.o: main.cpp City.h MedicalExecutive.h
	g++ -g -std=c++11 -c main.cpp

City.o: City.h City.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c City.cpp

MedicalExecutive.o: MedicalExecutive.h MedicalExecutive.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp 
	g++ -g -std=c++11 -c MedicalExecutive.cpp

clean:
	rm *.o lab03

