#include <iostream>
#include <cmath>
#include "ASA.h"

ASA::ASA(int cnt) : _D(cnt+1, vector<int>(1)), D(cnt+1, vector<int>(1)) {
// cnt = levels of ASA = k
    level = cnt;
    for(int i=0; i<=cnt; ++i){
        size[i] = pow(2, i);
        // modify the capacities of each vector to pow(2, i)
        D[i].reserve(size[i]);
        _D[i].reserve(size[i]);
        // clear the elements added in initialization list above
        D[i].clear();
        _D[i].clear();
    }
};

void ASA::insert(int data){
    // starting from level 0
    // if the real array of this level is empty
    //      -> add data to the real array
    // if the real array of this level is filled 
    //      -> add data to the tmp array 
    //       -> real array of the next level = merge(real array, tmp array) 
    //        -> clear all elements in both real and tmp arrays of this level
    if(D[0].empty()){
        D[0].push_back(data);
    }else{
        _D[0].push_back(data);

        int index=0;
        while(!_D[index].empty()){
            if(D[index+1].empty()){
                merge(D[index], _D[index], D[index+1]);
                D[index].clear();
                _D[index].clear();
            }else{
                merge(D[index], _D[index], _D[index+1]);
                D[index].clear();
                _D[index].clear();
            }
            ++index;
        }
    }
}

bool ASA::search(int target){
    for(int i=0; i<=level; ++i){
        if(!D[i].empty()){
            return binarySearch(D[i], target);
        }
    }
    return false;
}

void ASA::display(){
    for(int i=0; i<=level; ++i){
        cout << "level: " << i << endl;
        auto it = D[i].begin();
        for( ; it != D[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
}

void ASA::merge(const vector<int> &v1, const vector<int> &v2, vector<int> &out){
    // use iterator to traverse data stored in the array(in the form of vector)
    auto it1 = v1.begin(), it2 = v2.begin();
    while(true){
        // terminate when both arrays are completely traversed
        if(it1 == v1.end() && it2 == v2.end()){
            break;
        }
        // operate on the other array when either one is completely traversed
        else if(it1==v1.end()){
            out.push_back(*it2);
            ++it2;
        }else if(it2==v2.end()){
            out.push_back(*it1);
            ++it1;
        }
        // add the smaller date to the outcome array
        // sorting executed here
        else if(*it1 <= *it2){
            out.push_back(*it1);
            ++it1;
        }else{
            out.push_back(*it2);
            ++it2;
        }
    }
}

// return true if target value can be found in this array
bool ASA::binarySearch(const vector<int> &v, const int target){
    int low = 0, high = v.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(v[mid] == target){
            return true;
        }else if(v[mid] > target){
            high = mid-1;
        }else if(v[mid] < target){
            low = mid+1;
        }
    }
    return false;
}