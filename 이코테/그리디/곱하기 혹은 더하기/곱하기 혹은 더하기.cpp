#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a;
    cin >> a;
    vector<int> v;
    for(int i =0; i < a.length(); i++){
        v.push_back(a[i]-'0');
    }
    int answer=0;
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        if(iter == v.begin()){
            answer = *iter;
            continue;
        }
        if(answer == 1 || answer == 0 || *iter == 0 || *iter==1){
            answer += *iter;
        }
        else{
            answer *= *iter;
        }
    }
    cout << answer;
}