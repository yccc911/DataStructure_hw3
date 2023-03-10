#include <iostream>
#include <fstream>
#include <cmath>
#include "SourceCode.h"

using namespace std;

int main(){

    ofstream insertRes("insert.result", ios::out);
    ofstream searchRes("search.result", ios::out);
    // random numbers produced in advance
    ifstream insertF;
    insertF.open("../random/random.insert", ios::in);
    ifstream search;
    search.open("../random/random.search", ios::in);

    for(int i=10; i<=30; ++i){
        for(int time=0; time<5; ++time){
            int size = pow(2, i);
            
            // typedef node* pnode;
            // the root
	        pnode DS = NULL;

            clock_t start = clock();
            // inserting
            int tmp;
            for(int j=0; j<size; ++j){
                insertF >> tmp;
                insert(DS, tmp);
            }
            clock_t end = clock();
            insertRes << (float)(end - start)/CLOCKS_PER_SEC << endl;

            start = clock();
            // saerching
            for(int j=0; j<100000; ++j){
                search >> tmp;
                find(DS, tmp);
            }
            end = clock();
            searchRes << (float)(end - start)/CLOCKS_PER_SEC << endl;
        }
        insertRes << endl;
        searchRes << endl;
    }

    insertRes.close();
    searchRes.close();
    insertF.close();
    search.close();
    return 0;
}