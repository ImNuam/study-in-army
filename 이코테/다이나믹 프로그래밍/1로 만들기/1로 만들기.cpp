#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[1000001];
    for(int i=1; i<=n; i++){ //다이나믹 프로그래밍을 풀 때 점화식으로 표현할 수 있는지 생각을 해보자
        if(i==1) dp[i] = 0;
        if(i==3 || i==5 || i==2) dp[i]=1;
        else{
            int x;
            x=dp[i-1];
            if(i%2==0) x=min(x, dp[i/2]);
            if(i%3==0) x=min(x,dp[i/3]);
            if(i%5==0) x=min(x,dp[i/5]);
            x++;
            dp[i]=x;
        }
    }
    cout << dp[n] << endl;
}