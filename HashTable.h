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

    struct HashNode {
        int data;
        HashNode *next;
    };

public:

    HashTable();
    deque<string> chunk(string sentence);
    int HashFunction(deque<string> words);

};