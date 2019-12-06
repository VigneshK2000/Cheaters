#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

class HashTable{

private:


//    struct HashNode {
//        unsigned int data;
//        HashNode *next;
//    };

//     Seg fault if size is 1 million

    // vector<int> *(hashtable[255000]);
    vector<int> *hashtable;
    int chart[500][500];

public:

    HashTable();
    void chunk(string sentence, unsigned int fileNum, int inputn_count);
    void HashFunction(deque<string> words, unsigned int fileNum);
    string lineClean(string fullSen);
    void plagiarismTable(string names[], int col, int numFiles);
    int getSize();

};
