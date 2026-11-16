#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout << "Enter number of vertices and edges: " << endl;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency List: " << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " ----> ";
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    queue<int> Q;
    int visited[n+1];
    memset(visited,0,sizeof(visited));

    cout << "Enter the starting vertex for BFS: ";
    int start;
    cin >> start;

    Q.push(start);
    visited[start] = 1;
    cout << "BFS Traversal: ";
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        cout << node << " ";

        for(int i = 0; i < adj[node].size(); i++){
            int nextNode = adj[node][i];
            if(!visited[nextNode]){
                Q.push(nextNode);
                visited[nextNode] = 1;
            }
        }
    }

    return 0;
}