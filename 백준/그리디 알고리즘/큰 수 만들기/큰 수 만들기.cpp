#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a==b) return false;
    string ab=a+b;
    string ba=b+a;
    if(ab>ba) return true;
    else return false;
}

int main(){
    int n;
    vector<string> v;
    cin >> n;
    int flag=0;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        if(tmp!="0") flag++;
        v.push_back(tmp);
    }
    if(flag!=0){
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    cout << endl;
    return 0;
    }
    else{
        cout << 0 << endl;
        return 0;
    }
}