#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int table[1025][1025];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    vector<int> results;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            table[i][j] = table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + tmp;
        }
    }

    for (int k = 0; k < m; k++)
    {
        int c1, l1, c2, l2;
        cin >> c1 >> l1 >> c2 >> l2;
        int result = table[c2][l2] - table[c1 - 1][l2] - table[c2][l1 - 1] + table[c1 - 1][l1 - 1];
        results.push_back(result);
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << "\n";
    }
}