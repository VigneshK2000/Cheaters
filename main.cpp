#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include "HashTable.h"


using namespace std;

string lineClean(string line){
    string answer = "";
    for (auto x : line) {
        if (x == '\n'){
            return answer;
//            cout << answer << endl;
//            answer = "";
        } else {
            answer += x;
        }
    }
    return answer;
}

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main()
{
//    deque<string> myDeque;
    HashTable test;
    deque<string> check = test.chunk("Nineteen Eighty-Four was written between the years of 1945 and 1948. Orwell got the title from switching the last two numbers of the publication date. In OrwellÕs criticism of a perfect society, his book became known as one of the greatest anti-utopian novels of all time. The bookÕs message is so powerful that some say it went so far as to prevent the sinister future from realizing itself.");

    test.HashFunction(check);


    string tester;

    for (auto i = check.cbegin(); i < check.cend(); i++){
        cout << *i << endl;
    }


//    string dir = string("sm_doc_set");
//    vector<string> files = vector<string>();
//
//    getdir(dir,files);
//
//    for(auto i = files.begin() + 2; i < files.end(); i++){
//
//        string line;
//        string test;
//        string filepath = dir + '/' + *i;
//
//        ifstream myFile(filepath);
//        while (getline(myFile,line)){
//
//            test = lineClean(line);
//            cout << test << "\n";
//
//        }
//        myFile.close();
//    }

//    string test = "abcd";
//
//    for (char i : test){
//        cout << i << endl;
//    }
    return 0;
}