#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    string bomb;
    cin >> str >> bomb;
    stack<char> stk;
    char tmp[37];

    for (int i = 0; i < str.length(); i++)
    {
        stk.push(str[i]);
        if (stk.top() == bomb[bomb.length() - 1])
        {
            for (int j = 0; j < bomb.length(); j++)
            {
                if (stk.size()>0 && bomb[bomb.length() - j - 1] == stk.top())
                {
                    tmp[j] = stk.top();
                    stk.pop();
                }
                else
                {
                    while (j > 0)
                    {
                        stk.push(tmp[j - 1]);
                        j--;
                    }
                    break;
                }
            }
        }
    }
    if (stk.size() == 0)
    {
        cout << "FRULA" << endl;
    }
    else
    {
        char result[1000001];
        int n = 0;
        while (!stk.empty())
        {
            result[stk.size() - 1] = stk.top();
            stk.pop();
            n++;
        }
        for (int i = 0; i < n; i++)
        {
            cout << result[i];
        }
    }
}