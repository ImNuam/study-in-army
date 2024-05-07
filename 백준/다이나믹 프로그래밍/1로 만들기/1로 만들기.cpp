#include <iostream>
#include <string.h>
using namespace std;

int dp[1000001];

int recursive(int n){
    int& ret = dp[n];
    if(ret != -1) return ret;
    if(n == 1) return 0;
    else{
        ret = recursive(n-1)+1;
        if(n%3 == 0){
            ret = min(ret, recursive(n/3)+1);
        }
        if(n%2 == 0){
            ret = min(ret, recursive(n/2)+1);
        }
        return ret;
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    int x;
    cin >> x;
    for(int i=1; i<x; i++){
        recursive(i);
    }
    cout << recursive(x) << endl;
}