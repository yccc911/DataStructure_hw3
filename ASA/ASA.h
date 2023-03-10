#include <vector>

using namespace std;

class ASA{
    public:
    ASA(int cnt=10);

    void insert(int data);
    bool search(int target);

    void display();

    private:
    vector<vector<int> > D, _D;
    // D[0] = sorted array of size pow(2, 0)
    // D[1] = sorted array of size pow(2, 1)
    // ...
    // D[i] = sorted array of size pow(2, i)
    int size[31];
    int level;

    void merge(const vector<int> &, const vector<int> &, vector<int> &);
    bool binarySearch(const vector<int> &, const int);
};