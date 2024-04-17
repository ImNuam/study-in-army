#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<vector<int>> goldMine[t];
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < n; j++)
        {
            goldMine[i].push_back(vector<int>(m));
            for (int k = 0; k < m; k++)
            {
                int temp;
                cin >> temp;
                goldMine[i][j][k]=temp;
            }
        }
    }
    for(int i=0; i<t;i++){
        int result=0;
        for(int k=0; k<goldMine[i][0].size(); k++){
            for(int j=0; j<goldMine[i].size(); j++){
                if(k==0) continue;
                else{
                    int x=goldMine[i][j][k-1];
                    if(j>0) x=max(x, goldMine[i][j-1][k-1]);
                    if(j<goldMine[i].size()-1) x=max(x, goldMine[i][j+1][k-1]);
                    goldMine[i][j][k]=goldMine[i][j][k]+x;
                    if(result<goldMine[i][j][k]) result = goldMine[i][j][k];
                }
            }
        }
        cout << result << endl;
    }
}