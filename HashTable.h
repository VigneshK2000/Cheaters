//
// Created by kvigg on 12/3/2019.
//

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

    vector<int> *hashtable;
    int chart[27][27];

public:

    HashTable();
    void chunk(string sentence, unsigned int fileNum);
    void HashFunction(deque<string> words, unsigned int fileNum);
    string lineClean(string fullSen);
    void plagiarismTable(string names[]);
    int getSize();

};