#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    return a>b;
}
int main(){
    int n, m; //n은 화폐 종류 개수, m은 전체 가격
    cin >> n>> m;
    vector<int> moneys;
    vector<int>  dp(10000, 10000);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        moneys.push_back(temp);
    }
    sort(moneys.begin(), moneys.end(), compare);
    for(int i =1; i<=m; i++){
        int x=dp[i];
        for(int j=0; j<n; j++){
            if(i==moneys[j]) {x=1; break;}
            else if(i-moneys[j]>0 && dp[i-moneys[j]]!=-1) x= min(x, dp[i-moneys[j]]+1);
        }
        if(x==10000) dp[i]=-1;
        else dp[i] = x;
    }
    cout << dp[m] << endl;
}