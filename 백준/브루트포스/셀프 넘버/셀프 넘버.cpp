#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[10001];

int main()
{
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i < 10000; i++)
    {
        int num = i;
        while (num <= 10000)
        {
            string s_num = to_string(num);
            for (string::iterator iter = s_num.begin(); iter != s_num.end(); iter++)
            {
                num=num+(*iter)-'0';
            }
            arr[num]=1;
        }
    }
    for(int i=1; i<10000; i++){
        if(arr[i]==0){
            cout << i << " ";
        }
    }
}