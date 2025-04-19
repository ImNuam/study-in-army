#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return abs(a) < abs(b);
    }
};
int n;
priority_queue<int> pos;
priority_queue<int, vector<int>, cmp> neg;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp > 0)
        {
            pos.push(tmp);
        }
        else
        {
            neg.push(tmp);
        }
    }

    int sum = 0;
    while (!pos.empty())
    {
        int a = pos.top();
        pos.pop();
        if (!pos.empty())
        {
            int b = pos.top();
            pos.pop();
            if (a * b > a + b)
                sum += a * b;
            else
                sum += a + b;
        }
        else
        {
            sum += a;
        }
    }
    while (!neg.empty())
    {
        int a = neg.top();
        neg.pop();
        if (!neg.empty())
        {
            int b = neg.top();
            neg.pop();
            if (a * b > a + b)
                sum += a * b;
            else
                sum += a + b;
        }
        else
        {
            sum += a;
        }
    }

    printf("%d\n", sum);
}