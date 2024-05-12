#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
vector<vector<pair<int, int>>> cases;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int n;
        cin >> n;
        cases.push_back(vector<pair<int, int>>());
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            cases[i].push_back({a, b});
        }
        sort(cases[i].begin(), cases[i].end());
    }
    for(int i=0; i<cnt; i++){
        int result=1;
        int tmp=0;
        for(int j=1; j<cases[i].size(); j++){
            if(cases[i][tmp].second>cases[i][j].second){
                tmp=j;
                result++;
            }
        }
        cout << result << endl;
    }
}