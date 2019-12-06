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


  const int MILLION = 1000000;
  hashtable = new vector<int>[MILLION];


    //Need to malloc in future of different doc set sizes
    for (int i = 0; i < 25; i++){
        for (int j = 0; j< 25; j++){

            chart[i][j] = 0;

        }
    }

};

int HashTable::getSize() {
    return 1000000;

}

void HashTable::HashFunction(deque<string> words, unsigned int fileNum) {

    //long long unsigned int key = 0;

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
    for(char c : newSentence) {
        hash += (hash + c * exponent);
        hash %= 1000000;
        exponent = (exponent * base) % 1000000;
    }

//    cout << hash << " and " << fileNum << endl;
    (hashtable[hash]).push_back(fileNum);
//    cout << "lkdlkdl" << endl;
//   for(vector <int> :: iterator var = hashtable[hash].begin(); var != hashtable[hash].end(); var++)
//       cout << hash << ": " << hashtable[hash].at(*var) << endl;


//    cout << hashtable[hash][0] << endl;


//    cout << newSentence << " " << endl;

}

void HashTable::chunk(string sentence, unsigned int fileNum, int inputn_count) {
    int fullstop = 0;
    deque<string> chunk;
    string word;
    int n_count = 0;

    int sentenceLength = sentence.length();
    int charCount = 0;

    for (char i : sentence){

        if(i < 0 || (i >= 33 && i <= 47) || (i >= 58 && i <= 64)) {
            continue;
        }
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

        if (n_count == inputn_count){

            HashFunction(chunk, fileNum);

            chunk.pop_front();
            n_count -= 1;
        }
    }
}

string HashTable::lineClean(string fullSen){

    for (int i = 0; i < fullSen.length(); i ++) {
        //Caps to lowercase
        if (fullSen[i] >= 65 && fullSen[i] <= 90) {
            fullSen[i] += 32;
        } //Fake characters
    }
    return fullSen;
}


void HashTable::plagiarismTable(string names[], int col) {

    int size = getSize();
    struct sortList {
        int value;
        int x;
        int y;
    };
    vector<sortList> list;
    int m = 0;

    for (unsigned int i = 0; i < size; i++) {

        for (int j = 0; j < (hashtable[i]).size(); j++) {

            for (int k = j+1; k < (hashtable[i]).size(); k++) {
                //cout << i << " "<< (hashtable[i]).at(j) << " " << (hashtable[i]).at(k) << endl;
                chart[hashtable[i].at(j)][hashtable[i].at(k)] += 1;
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
           // cout << chart[i][j] << " " << i  <<names[i+2] << " " << j << names[j+2]<< endl;
            if (chart[i][j] > col) {
                list.push_back(sortList());
                list[m].value = chart[i][j];
                list[m].x = i;
                list[m].y = j;
                m++;
                //cout << chart[i][j] << ": " << names[i+2] << ", " << names[j+2] << endl;
            }
        }

    }

    for (int i = 0; i < list.size(); i++){
        for (int j = i + 1; j<list.size(); j++ ) {

            sortList temp;

            if (list[j].value > list[i].value) {
                //largest = i;

                temp = list[i];
                list[i] = list[j];
                list[j] = temp;


            }
        }

    }

    for (unsigned int i = 0; i < list.size(); i++) {
        cout << list[i].value << ": " << names[list[i].x+2] << ", " << names[list[i].y+2] << endl;
    }

}