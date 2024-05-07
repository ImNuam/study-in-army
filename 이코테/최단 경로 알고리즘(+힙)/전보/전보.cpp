#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int n, m, c;
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start]=0;
    while(!pq.empty()){
        int dist= -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now]< dist) continue;
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(){
    cin >> n >> m >> c;
    for(int i=0; i<m; i++){

    }
}