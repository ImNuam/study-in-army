#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int dp[5001];
string str;

int recursive(int n)
{
    if(str[0]=='0') return 0;
    int &ret = dp[n];
    if(ret!=-1) return ret;
    if (n == 0 || n == 1)
        ret = 1;
    else
    {
        ret=0;
        if(str[n-1]!='0') ret = recursive(n - 1)%1000000;
        int temp = (str[n-2]-'0')*10 + (str[n-1]-'0');
        if (temp>=10 && temp<=26)
        {
            ret = (ret + recursive(n-2))%1000000;
        }
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> str;
    cout << recursive(str.length()) << endl;
}