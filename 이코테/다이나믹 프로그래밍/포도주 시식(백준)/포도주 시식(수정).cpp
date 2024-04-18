#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int t;
vector<int> table;
int dp[10000];
int isDrink[10000];

int recursion(int n, int drink){
    int& ret = dp[n];
    if(n==0) ret = table[n];
    if(n==1) ret = dp[n-1] + table[n];
    if(ret!= -1) return ret;
    ret=recursion(n-1, 0);
    if(drink == 1 &&isDrink[n-1]) ret=max(ret, recursion(n-1, 1));
    if(drink==1 && ret == recursion(n-1, 0)){
        isDrink[n]=1;
    }
    return ret;
}

int main(){
    cin >> t;
    table.resize(t);
    memset(isDrink,0,sizeof(isDrink));
    memset(dp, -1,sizeof(dp));
    for(int i=0; i<t; i++){
        int temp;
        cin >>temp;
        table[i] = temp;
    }
    cout<< max(recursion(t-1, 0), recursion(t-1, 1));
}