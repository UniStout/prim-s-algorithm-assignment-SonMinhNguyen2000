//All procedures including main
#include <iostream>
#include <vector>
#include <sstream>
#include "prim.h"

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST(graph);
    return 0;
}