#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> graph; // Adjacency list representation of the graph

int prim(int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Distance of each vertex from the MST
    vector<bool> visited(n, false); // Track visited vertices
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap to select the minimum edge

    dist[start] = 0; // Start vertex has distance 0
    pq.push({0, start});

    int mstCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        mstCost += dist[u];

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }

    return mstCost;
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight; // Input edge (u, v) with weight

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int start;
    cin >> start; // Starting vertex for MST

    int mstCost = prim(start);

    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;

    return 0;
}
