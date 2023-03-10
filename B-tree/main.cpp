#include <iostream>
#include <fstream>
#include <cmath>
#include "SourceCode.h"

using namespace std;

int main(){

    ofstream insertRes("insert.result", ios::out);
    ofstream searchRes("search.result", ios::out);
    // random numbers produced in advance
    ifstream insert;
    insert.open("../random/random.insert", ios::in);
    ifstream search;
    search.open("../random/random.search", ios::in);

    for(int i=10; i<=30; ++i){
        for(int time=0; time<5; ++time){
            int size = pow(2, i);

            // degree = maximum number of children = 100
            BPlusTree<int> DS(100);

            clock_t start = clock();
            int tmp;
            // inserting
            for(int j=0; j<size; ++j){
                insert >> tmp;
                DS.insert(tmp);
            }
            clock_t end = clock();
            insertRes << (float)(end - start)/CLOCKS_PER_SEC << endl;

            start = clock();
            // searching
            for(int j=0; j<100000; ++j){
                search >> tmp;
                DS.search(tmp);
            }
            end = clock();
            searchRes << (float)(end - start)/CLOCKS_PER_SEC << endl;
        }
        insertRes << endl;
        searchRes << endl;
    }

    insertRes.close();
    searchRes.close();
    insert.close();
    search.close();
    return 0;
}