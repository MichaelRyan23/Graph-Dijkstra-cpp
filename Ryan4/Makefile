output: main.o Tree.o
	g++ -std=c++11 -o output main.o Tree.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Tree.o: Tree.h Tree.cpp
	g++ -std=c++11 -c Tree.cpp

clean:
	rm output main.o Tree.o