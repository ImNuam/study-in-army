#include <iostream>
#include <vector>
#include <queue>
#define INF INT32_MAX

using namespace std;

class Node{
    public:
        int distance;
        vector<pair<int, int>> edges;
        Node() : distance(INF), edges(vector<pair<int,int>>()){};
};
 struct cmp{
        bool operator()(Node a, Node b){
            return a.distance>b.distance;
        }
    };
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e, start;
    cin >> v >> e >> start;
    vector<Node> nodes;
    for(int i=0; i<=v; i++){
        nodes.push_back(Node());
    }
    for(int i=0; i<e; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        nodes[from].edges.push_back(make_pair(to, weight));
    }
    nodes[start].distance=0;
    
    priority_queue<Node, vector<Node>, cmp> q;
    q.push(nodes[start]);
    while(!q.empty()){
        Node here=q.top();
        q.pop();
        for(int i=0; i<here.edges.size(); i++){
            if(nodes[here.edges[i].first].distance>here.distance+here.edges[i].second){
                nodes[here.edges[i].first].distance=here.distance+here.edges[i].second;
                q.push(nodes[here.edges[i].first]);
            }
        }
    }
    for(int i=1; i<=v; i++){
        if(nodes[i].distance==INF){
            cout << "INF"<<endl;
        }
        else cout << nodes[i].distance << endl;
    }
}