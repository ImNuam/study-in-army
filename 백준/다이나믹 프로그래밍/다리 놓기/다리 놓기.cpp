#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

long long dp[31][31];

long long recursive(int n, int m){
    long long& ret = dp[n][m];
    if(ret!=-1){
        return ret;
    }
    else{
        ret=0;
        m--;
        n--;
        while(m>=n){
            ret+=recursive(n, m);
            m--;
        }
        return ret;
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<31; i++){
        dp[1][i]=i;
    }
    int n, m;
    int cnt;
    vector<pair<int, int>> testcases;
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        cin >> n >> m;
        testcases.push_back({n,m});
    }
    for(int i=0; i<testcases.size(); i++){
        cout << recursive(testcases[i].first, testcases[i].second) << endl;
    }
}