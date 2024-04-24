/*
문제 공략
1. 번호는 신경 쓰지 않고(이어진 좌석의 개수가 중요!), vip를 기준으로 잘라서 생각한다.
2. 함수는 result()와 recursive(int n) 두 개
3. result 함수에서는 recursive 함수의 결과들을 곱한다.
4. recursive 함수에서는 n개짜리 좌석들을 나열할 수 있는 경우를 센다.
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool vips[41];
int dp[41]; // recursive 결과값 저장
// int cache[41]; //-1이면 아직 안된거고, cache에 들어가 있는 것이 마지막이 바뀐 경우의 수를 뜻함.
int t, vipCount;
int recursive(int n)
{
    int &ret = dp[n];
    if (ret != -1)
        return ret;
    if (n == 1 || n == 0)
    {
        ret = 1;
    }
    else ret = recursive(n - 2) + recursive(n - 1);
        return ret;
}

int result()
{
    int ret=1;
    int count = 0;
    for (int i = 1; i<=t+1;i++){
        
        if(vips[i] || i==t+1){
            ret*=recursive(count);
            count = 0;
        }
        else count++;
    }
    return ret;
}

int main()
{
    cin >> t >> vipCount;
    memset(vips, 0, sizeof(vips));
    memset(dp, -1, sizeof(dp));
    // memset(cache, -1, sizeof(cache));
    for (int i = 0; i < vipCount; i++)
    {
        int temp;
        cin >> temp;
        vips[temp] = true;
    }
    cout << result() << endl;
}