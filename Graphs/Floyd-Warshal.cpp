#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    int dist[n+1][n+1];
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0; // Distance from a node to itself is 0
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    cout << "Enter the edges (u v weight):" << endl;
    for(int i = 1; i <=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // In case of multiple edges, take the minimum weight
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Shortest distance between source and destination nodes:" << endl;
    int src, dest;
    cin >> src >> dest;
    if(dist[src][dest] == INF){
        cout << "No path exists between node " << src << " and node " << dest << endl;
    } else {
        cout << "Shortest distance from node " << src << " to node " << dest << " is: " << dist[src][dest] << endl;
    }  

    cout << endl;
}