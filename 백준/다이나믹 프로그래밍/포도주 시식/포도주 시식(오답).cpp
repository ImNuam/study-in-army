#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    int dp[3];
    memset(dp, 0, sizeof(dp));
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(i%3==0){
            dp[0]+=temp;
            dp[2]+=temp;
        }
        if(i%3==1){
            dp[0]+=temp;
            dp[1]+=temp;
        }
        if(i%3==2){
            dp[1]+=temp;
            dp[2]+=temp;
        }
    }
    int result=max(max(dp[0],dp[1]),dp[2]);
    cout << result;
    
}