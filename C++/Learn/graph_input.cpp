#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
// #include <sstream>
using namespace std;

int main()
{

    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m; // Read number of nodes and edges

    // Create an adjacency list
    // 1-based indexing is preferred since inputs are usually 1 to N
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // For an UNDIRECTED graph, add the edge both ways:
        adj[u].push_back(v);
        adj[v].push_back(u);

        /* NOTE: If the graph is DIRECTED (u -> v only),
        you would ONLY keep: adj[u].push_back(v);
        */
    }

    
    // for weighted graph, you can use a vector of pairs:
    // vector<vector<pair<int, int>>> adj(n + 1);

    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;

    //     adj[u].push_back({v, w});
    //     adj[v].push_back({u, w}); // Omit this line if it's a directed graph
    // }

    return 0;
}
