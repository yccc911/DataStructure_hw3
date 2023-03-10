#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main(){

    ofstream random("random.random", ios::out);

    for(int i=10; i<=30; ++i){
        int size = pow(2, i);

        random_device seed;
        default_random_engine generator(seed());
        uniform_int_distribution<int> uniform(1, pow(2, 30));

        for(int i=0; i<size; ++i){
            random << uniform(generator) << endl;
        }
        random << endl;
    }

    random.close();
    return 0;
}