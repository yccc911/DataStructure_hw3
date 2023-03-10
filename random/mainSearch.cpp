#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main(){

    ofstream random("random.search", ios::out);

    random_device seed;
    default_random_engine generator(seed());
    uniform_int_distribution<int> uniform(1, pow(2, 30));

    for(int i=0; i<100000; ++i){
        random << uniform(generator) << endl;
    }

    random.close();
    return 0;
}