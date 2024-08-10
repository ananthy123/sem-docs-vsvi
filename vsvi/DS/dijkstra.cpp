/* Arguably the most important graph algo. The way this works is that it uses something called a priority queue (heap) to push the initial source node. From now on, we will be working with weighted edges, so we will be storing 3 things, the source, dest and weight of every edge.
The algorithm starts by pushing the source node into the priority queue with a distance of 0. Then, it repeatedly selects the node with the smallest distance from the priority queue and explores its neighboring nodes. For each neighboring node, the algorithm updates its distance if a shorter path is found. This process continues until all nodes have been visited or the priority queue becomes empty.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    // Create a graph
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    // Add edges to the graph
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
