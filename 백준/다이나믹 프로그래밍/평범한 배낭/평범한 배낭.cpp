#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, k;
int w[101], v[101];
// bool cache[101][101];
int dp[101][100001];

int recursive(int i, int k){
    if(i>n) return 0;
    int& ret = dp[i][k];
    if(ret!= -1) return ret;
    if(k>=w[i]) ret = max(recursive(i+1, k-w[i])+v[i], recursive(i+1, k));
    else ret = recursive(i+1, k);
    return ret;
}

int main(){
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    cout << recursive(1, k) << endl;
}
