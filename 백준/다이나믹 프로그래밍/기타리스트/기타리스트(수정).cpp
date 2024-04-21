//기존 코드 문제점 : 메모리 소모가 너무 크다.(n이 크면 2^100-1개의 int형 변수를 만들어야 됨)
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int table[51];
bool dp[51][1001];
int n, start, m;

int recursive(int n)
{
    if(n==0){
        dp[n][start]=true;
        return start;
    }
    else{
        int result=-1;
        int check=0;
        for(int i=0; i<1001; i++){
            if(dp[n-1][i]==true){
                
                if((check=i+table[n])<=m){
                    dp[n][check]=true;
                    result=max(result, check);
                }
                if((check=i-table[n])>=0){
                   dp[n][check]=true; 
                   result=max(result, check);
                }
            }
        }
        return result;
    }
    
}

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n >> start >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
    }
    for (int i = 0; i < n; i++)
        recursive(i);
    std::cout << recursive(n) << endl;
}