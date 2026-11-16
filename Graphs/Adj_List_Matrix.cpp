#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    int adj[n+1][n+1];
    memset(adj,0,sizeof(adj));
    vector<int> adjList[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        adj[u][v] += 1;
        adj[v][u] += 1;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "Adjacency Matrix: " << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Adjacency List: " << endl;
    for(int i=1;i<=n;i++){
        cout << i << " ----> ";
        for(int j=0;j<adjList[i].size();j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}
