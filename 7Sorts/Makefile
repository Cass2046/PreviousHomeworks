lab07: main.o SortTimer.o  
	g++ -g -std=c++11 -Wall main.o SortTimer.o -o lab07
main.o: main.cpp Bubble.h Bubble.hpp Insertion.h Insertion.hpp Merge.h Merge.hpp Quick.h Quick.hpp Selection.h Selection.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
SortTimer.o: SortTimer.cpp Bubble.h Bubble.hpp Insertion.h Insertion.hpp Merge.h Merge.hpp Quick.h Quick.hpp Selection.h Selection.hpp
	g++ -g -std=c++11 -Wall -c SortTimer.cpp
clean:
	rm *.o lab07 