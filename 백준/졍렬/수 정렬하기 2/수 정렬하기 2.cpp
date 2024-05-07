#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++){
        cout << (*iter) << "\n";
    }
}