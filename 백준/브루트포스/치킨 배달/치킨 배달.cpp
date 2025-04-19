#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int arr[51][51]; //0은 빈 칸, 2는 치킨집, 1은 집
int n, m; //n은 지도의 크기, m은 폐업시키지 않을 치킨집의 개수
int SmallestCityDistance=1e9;
vector<pair<int, int>> chicks;
vector<pair<int, int>> houses;
int distance(pair<int, int> start, pair<int, int> end){
    return abs(start.first-end.first)+abs(start.second-end.second);
}

void executeDfs(vector<int>& visited, int idx, int chickenCount, int select){
    if(select==0){
        int cityDistance = 0;
        for(int i=0; i<houses.size(); i++){
            int chickenDistance=1e9;
            for(int j=0; j<visited.size(); j++){
                chickenDistance = min(chickenDistance, distance(houses[i], chicks[visited[j]]));
            }
            cityDistance+=chickenDistance;
        }
        if(cityDistance<SmallestCityDistance){
            SmallestCityDistance=cityDistance;
        }
    }
    else{
    for(int i=idx; i<chickenCount; i++){
        visited.push_back(i);
        executeDfs(visited, i+1, chickenCount, select-1);
        visited.pop_back();
    }
    }
}

void dfs(int idx, int chickenCount, int select){
    vector<int> visited;
    for(int i=idx; i<chickenCount; i++){
        visited.push_back(i);
        executeDfs(visited, i+1, chickenCount, select-1);
        visited.pop_back();
    }
}

int main(){
    memset(arr, -1, sizeof(arr));
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                chicks.push_back({i,j});
            }
            if(arr[i][j]==1){
                houses.push_back({i, j});
            }
        }
    }
    dfs(0, chicks.size(), m);
    cout << SmallestCityDistance << endl;

}