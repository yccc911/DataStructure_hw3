#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream insertData;
    insertData.open("insert.result", ios::in);
    ifstream searchData;
    searchData.open("search.result", ios::in);

    float insertave[18]={0};
    float searchave[18]={0};
    char tmp[15];
    float temp;
    for(int i=0; i<18; ++i){
        for(int j=0; j<5; ++j){
            insertData >> tmp;
            temp = stod(tmp);
            insertave[i] += temp;
            searchData >> tmp;
            temp = stod(tmp);
            searchave[i] += temp;
        }
    }
    insertData.close();
    searchData.close();

    ofstream insertAve("insert.average", ios::out);
    ofstream searchAve("search.average", ios::out);
    for(int i=0; i<18; ++i){
        insertave[i]/=5;
        insertAve << insertave[i] << endl;
        searchave[i]/=5;
        searchAve << searchave[i] << endl;
    }
    insertAve.close();
    searchAve.close();

    return 0;
}