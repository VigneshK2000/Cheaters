#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

class HashTable{

private:

    struct HashNode {
        unsigned int data;
        HashNode *next;
    };

//     Seg fault if size is 1 million
    HashNode hashtable[255000];

public:

    HashTable();
    deque<string> chunk(string sentence, unsigned int fileNum);
    int HashFunction(deque<string> words, unsigned int fileNum);
    string lineClean(string fullSen);
//    void Insert(int key, int value);

};