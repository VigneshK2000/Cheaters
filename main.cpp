#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include "HashTable.h"
#include <stdlib.h>


using namespace std;


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

int main ( int argc, char *argv[] )
{
//    deque<string> myDeque;
//    HashTable test;
//    deque<string> check = test.chunk("Nineteen Eighty-Four was written between the years of 1945 and 1948. Orwell got the title from switching the last two numbers of the publication date. In OrwellÕs criticism of a perfect society, his book became known as one of the greatest anti-utopian novels of all time. The bookÕs message is so powerful that some say it went so far as to prevent the sinister future from realizing itself.");
//
//    test.HashFunction(check);

    int ncount =  atoi(argv[2]);
    int col = atoi(argv[3]);
    string dir = argv[1];
    vector<string> files = vector<string>();

    getdir(dir,files);
    string names[files.size()];

//    Get number of each file
    for (unsigned int i = 0;i < files.size();i++) {
        names[i] = files[i];
    }


    HashTable table;

    int j = 0;

    for(auto i = files.begin() + 2; i < files.end(); i++){


        string line;

        string filepath = dir + '/' + *i;

        ifstream myFile(filepath);

        while (getline(myFile, line)) {
            table.chunk(line, j, ncount);

        }

        j++;

        myFile.close();

    }

    table.plagiarismTable(names, col);

    return 0;
}