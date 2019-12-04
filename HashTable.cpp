//
// Created by kvigg on 12/3/2019.
//

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "HashTable.h"
#include <deque>

HashTable::HashTable(){

}

int HashTable::HashFunction(deque<string> words) {

    string sentence;
    for (auto it = words.begin(); it < words.cend(); it++){
        sentence += *it;
    }
    cout << sentence << endl;

    return 0;

}

deque<string> HashTable::chunk(string sentence) {
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
            HashFunction(chunk);

            while(!chunk.empty()){
                chunk.pop_front();
            }

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
        } else if (i == '.'){
            chunk.push_back(word);
            HashFunction(chunk);
            chunk.pop_front();
            word = "";
            fullstop = 1;
        } else {
            word += i;
        }

        if (n_count == 3){
            HashFunction(chunk);
            chunk.pop_front();
            n_count -= 1;
        }
    }
    return chunk;
}




