#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int total=0;
    for(string::iterator iter = s.begin(); iter!= s.end(); iter++){
        if(isdigit(*iter)) total+=*iter-'0';
        else cout << *iter; 
    }
    cout <<total << endl;
}