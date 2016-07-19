/**
 * Huang Jiaming
 * UofS, saskatoon, Canada
 * 18.07.2016
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LastKLines{
public:
    LastKLines(char *f, int k):filename(f), K(k){}
    void printLast10Lines(){
        ifstream file(filename);
        string line[K];
        int index = 0;
        while(file.peek() != EOF){
            getline(file, line[index % K]);
            index++;
        }
        // output the K lines
        int start = index > K ? (index % K) : 0;
        int lineNum = min(K, index);
        for (int i = start; i < (start+lineNum); i++){
            cout << line[start % K] << endl;
        }
    }
private:
    char *filename;
    const int K;
};