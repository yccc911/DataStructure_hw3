
#include <iostream>
#include <fstream>
#include <random>
#include "SourceCode.h"

using namespace std;

int main(){

    ofstream result("test.result", ios::out);

    for(int i=10; i<=30; ++i){
        for(int time=0; time<5; ++time){
            int size = pow(2, i);

            random_device seed;
            default_random_engine generator(seed());
            uniform_int_distribution<int> uniform(1, pow(2, 30));

            int *random = new int(size);
            for(int j=0; j<size; ++j){
                random[j] = uniform(generator);
            }

            skiplist DS;

            clock_t start = clock();
            // inserting
            for(int j=0; j<size; ++j){
                DS.insert_element(random[j]);
            }
            clock_t end = clock();
            result << (double)(end - start)/CLOCKS_PER_SEC << endl;

            delete random;
        }
        result << endl;
    }


    result.close();
    return 0;
}