#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet) {
    int minVal = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < mstSet.size(); v++) {
        if (!mstSet[v] && key[v] < minVal) {
            minVal = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge\tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[parent[i]][i] << endl;
    }
}

