#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>


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
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for(auto i = files.begin() + 2; i < files.end(); i++){
        string line;
        string test;
        string filepath = dir + '/' + *i;

        ifstream myFile(filepath);
        while (getline(myFile,line)){

            test = lineClean(line);
            cout << test << "\n";

        }
        myFile.close();
    }
    return 0;
}