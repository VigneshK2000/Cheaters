plagiarismCatcher: main.o HashTable.o
	g++ -oplagiarismCatcher main.o HashTable.o
main: main.cpp HashTable.h
	g++ -c main.cpp
HashTable: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp

