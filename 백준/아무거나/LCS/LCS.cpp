#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dp[1001][1001];




void LCS(string s1, string s2){
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i]==s2[j]){
                if(i!=0 && j!=0) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j]=1;
            }
            else{
                if(i>0 && j>0){
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);}
                else if(i==0 && j>0){
                    dp[i][j]=dp[i][j-1];
                }
                else if(i>0 && j==0){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
    }
}

int main(){
    string s1, s2;
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2;
    LCS(s1, s2);
    cout << dp[s1.size()-1][s2.size()-1] << endl;
}