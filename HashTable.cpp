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
    for (int i = 0; i < 500; i++){
        for (int j = 0; j< 500; j++){

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

    for (deque<string>::iterator it = words.begin(); it < words.end(); it++){
        sentence += *it;
    }
    newSentence = lineClean(sentence);

    //Hash function
    for (int i = 0; i < newSentence.length(); i++){
        hash += (hash + newSentence[i] * exponent);
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

    for (int i =0 ; i < sentence.length() ;i++){

        if(sentence[i] < 0 || (sentence[i] >= 33 && sentence[i] <= 47) || (sentence[i] >= 58 && sentence[i] <= 64)) {
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

        if (sentence[i] == ' '){
            chunk.push_back(word);
            n_count += 1;
            word = "";
        } else if (sentence[i] == '.' ){
            chunk.push_back(word);

            HashFunction(chunk, fileNum);
            chunk.pop_front();
            word = "";
            fullstop = 1;
        } else {
            word += sentence[i];
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
    //vector<sortList> list;
    sortList list[1000] = {} ;
    int m = 0;
	cout << "1" << endl;
    for (unsigned int i = 0; i < size; i++) {

        for (int j = 0; j < (hashtable[i]).size(); j++) {

            for (int k = j+1; k < (hashtable[i]).size(); k++) {
                //cout << i << " "<< (hashtable[i]).at(j) << " " << (hashtable[i]).at(k) << endl;
                chart[hashtable[i].at(j)][hashtable[i].at(k)] += 1;
            }
        }
    }
	cout << "2" << endl;

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
           // cout << chart[i][j] << " " << i  <<names[i+2] << " " << j << names[j+2]<< endl;
            if (chart[i][j] > col) {
                list[m].value = chart[i][j];
                list[m].x = i;
                list[m].y = j;
                m++;
                //cout << chart[i][j] << ": " << names[i+2] << ", " << names[j+2] << endl;
            }
        }

    }
	cout << "3" << endl;

    for (int i = 0; i < 1000; i++){
        for (int j = i + 1; j<1000; j++ ) {

            sortList temp;

            if (list[j].value > list[i].value) {
                //largest = i;

                temp = list[i];
                list[i] = list[j];
                list[j] = temp;


            }
        }

    }
	cout << "4" << endl;
        size_t n = sizeof(list)/sizeof(sortList);
	
    for (unsigned int i = 0; i < n; i++) {
//	cout << n << endl;
	int one =(list[i].x);

	int two = list[i].y;
	cout << one << endl;
//	cout << two << endl;
//	cout << names[2] << endl;
//	cout << names[0] << " " << names[1] << endl;
	if (list[i].value > 0){
        cout << list[i].value << ": " << names[one+2] << ", " << names[two+2] << endl;
	}
    }
	cout << "5" << endl;

}
