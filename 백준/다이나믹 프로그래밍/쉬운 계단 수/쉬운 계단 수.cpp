// 문제 해결 아이디어
// 첫 자리를 1, 2~8, 9로 나누어서 생각하자

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int t;
long long cache[100][10];
long long recursive(int n)
{
    long long ret;
    if (n == 1)
    {
        ret = 9;
        for(int i=1; i<10; i++){
            cache[1][i]=1;
        }
    }
    else
    {
        ret=0;
        ret+=(cache[n][0]=cache[n-1][1]% 1000000000);
        ret+=(cache[n][9]=cache[n-1][8]% 1000000000);
        for(int i=1; i<9; i++){
            cache[n][i]=(cache[n-1][i-1]+cache[n-1][i+1])% 1000000000;
            ret+=cache[n][i];
            ret%= 1000000000;
        }
        
    }
    return ret;
}

int main()
{
    cin >> t;
    long long result;
    for(int i=1; i<=t; i++){
        result = recursive(i);
    }
    cout << result<< endl;
}