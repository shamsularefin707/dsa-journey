#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

void djikstra(int src, vector<vector<pair<int,int>>>& adj, vector<int>& dist){
    fill(dist.begin(), dist.end(), INF);

    //min-heap priority queue to store (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue; //Skip if already a better distance is found

        for(auto edge: adj[u]){
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source node " << src << ":" << endl;
    for(int i = 1; i < dist.size(); i++){
        if(dist[i] == INF){
            cout << "Node " << i << ": Unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
    cout << endl;
}

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);
    cout << "Enter the edges (u v weight):" << endl;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    int startNode;
    cout << "Enter the starting node for Dijkstra's algorithm: ";
    cin >> startNode;

    vector<int> dist(n + 1);
    djikstra(startNode, adj, dist);

    return 0;
}