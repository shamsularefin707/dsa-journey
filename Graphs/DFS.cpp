#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
    visited[node] = 1;
    cout << node << " ";
    for(int neighbor: adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor, adj, visited);
        }
    }
}

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<int> visited(n + 1, 0);

    vector<vector<int>> adj(n + 1, vector<int>(0));
    
    cout << "Enter the edges (u v):" << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    cout << "DFS traversal starting from node select:" << endl;
    int startNode;
    cin >> startNode;
    cout << "DFS traversal: ";
    dfs(startNode, adj, visited);

    cout << endl;
    return 0;
}