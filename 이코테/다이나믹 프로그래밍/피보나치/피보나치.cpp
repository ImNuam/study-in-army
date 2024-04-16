#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> dpTable(2,1);
    for(int i=2; i<n; i++){
        dpTable.push_back(dpTable[i-2]+dpTable[i-1]);
    }
    cout << dpTable[n-1]<<endl;
}