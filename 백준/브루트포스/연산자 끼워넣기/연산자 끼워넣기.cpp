#include <iostream>
#include <cassert>
#include <set>
using namespace std;

int n;
int arr[11];
int add, sub, mul, di;
int M = -1e9;
int mm = 1e9;
void makeNum(int i, int a, int s, int m, int d, int ex)
{
    int ret;
    if (i == 0)
    {
        ret = arr[0];
        makeNum(i + 1, a, s, m, d, ret);
    }
    if (i == n)
    {
        if (M < ex)
        {
            M = ex;
        }
        if (mm > ex)
        {
            mm = ex;
        }
        return;
    }
    if (a > 0)
    {
        ret = ex + arr[i];
        makeNum(i + 1, a - 1, s, m, d, ret);
    }
    if (s > 0)
    {
        ret = ex - arr[i];
        makeNum(i + 1, a, s - 1, m, d, ret);
    }
    if (m > 0)
    {
        ret = ex * arr[i];
        makeNum(i + 1, a, s, m - 1, d, ret);
    }
    if (d > 0)
    {
        ret = ex / arr[i];
        makeNum(i + 1, a, s, m, d - 1, ret);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> add >> sub >> mul >> di;
    makeNum(0, add, sub, mul, di, 0);
    cout << M << '\n'
         << mm << endl;
}