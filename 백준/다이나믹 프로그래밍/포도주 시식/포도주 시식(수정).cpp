#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int t;
vector<int> table;
int dp[10000];

int recursion(int n){
    int& ret = dp[n];
    if(n==0) ret = table[n];
    if(n==1) ret = recursion(0) + table[n];
    if(ret!= -1) return ret;
    ret=recursion(n-1);
    ret=max(max(ret, recursion(n-2)+table[n]),recursion(n-3)+table[n-1]+table[n]);
    return ret;
}

int main(){
    cin >> t;
    memset(dp, -1,sizeof(dp));
    table.resize(t);
    for(int i=0; i<t; i++){
        int temp;
        cin >>temp;
        table[i] = temp;
    }
    cout<< recursion(t-1);
}