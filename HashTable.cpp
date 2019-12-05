#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "HashTable.h"
#include <deque>
#include <cmath>
#include <list>

HashTable::HashTable(){
    hashtable->data = 0;
    hashtable->next = NULL;
}

int HashTable::HashFunction(deque<string> words, unsigned int fileNum) {
    long long unsigned int key = 0;
    string sentence;
    int hash = 0;
    int base = 7;
    int exponent = 1;
    string newSentence;

    for (auto it = words.begin(); it < words.cend(); it++){
        sentence += *it;
    }
    newSentence = lineClean(sentence);

    //Hash function
    for(char c : newSentence){
        hash += (hash + c * exponent);
        hash %= 255000;
        exponent = (exponent * base) % 255000;
    }

    if(hashtable[hash].data == 0){
        hashtable[hash].data = fileNum;
        hashtable[hash].next = NULL;
    }
    else {
        //HashNode *entry =  new HashNode;
        HashNode *entry = NULL;
        entry->data = fileNum;
        hashtable[hash].next = entry;


    }
    cout << newSentence << endl;
    return 0;

}

deque<string> HashTable::chunk(string sentence, unsigned int fileNum) {
    int fullstop = 0;
    deque<string> chunk;
    string word;
    int n_count = 0;

    int sentenceLength = sentence.length();
    int charCount = 0;

    for (char i : sentence){

        charCount += 1;
        if (charCount == sentenceLength){
            chunk.push_back(word);
            HashFunction(chunk, fileNum);

            break;
        }

        if (fullstop == 1){
            fullstop = 0;
            continue;
        }

        if (i == ' '){
            chunk.push_back(word);
            n_count += 1;
            word = "";
        } else if (i == '.' ){
            chunk.push_back(word);
            HashFunction(chunk, fileNum);
            chunk.pop_front();
            word = "";
            fullstop = 1;
        } else {
            word += i;
        }

        if (n_count == 6){
            HashFunction(chunk, fileNum);
            chunk.pop_front();
            n_count -= 1;
        }
    }
    return chunk;
}

string HashTable::lineClean(string fullSen){

    for (int i = 0; i < fullSen.length(); i ++){

        if (fullSen[i] >= 65 && fullSen[i] <= 90){
            fullSen[i] += 32;
        }
        else if(fullSen[i] < 0){
            fullSen[i] = 0;
        }
    }
    return fullSen;
}

//void HashTable::Insert(int key, int value){
//    int val = HashFunction(key);

//}
