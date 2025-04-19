#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

map<int, vector<pair<int,int>>> tree;
int maxDistance=0;
int maxNode=0;
void dfs(int node, int distance, int visited){
    if(maxDistance<distance){
        maxDistance=distance;
        maxNode=node;
    }
    for(int i=0; i<tree[node].size(); i++){
        if(visited==tree[node][i].first) continue;   
        dfs(tree[node][i].first, distance+tree[node][i].second, node);
    }
}

void findMaxDistance(){
    dfs(1, 0, 0);
    maxDistance=0;
    dfs(maxNode, 0, 0);
}

int main(){
    int cnt, start, end, weight;
    cin >> cnt;
    for(int i=0; i<cnt-1; i++){
        cin >> start >> end >> weight;
        tree[start].push_back(make_pair(end, weight));
        tree[end].push_back({start, weight});
    }
    findMaxDistance();
    cout << maxDistance;
}