// DFS is simpler. if you have a node, if it's neighbour is not visited, visit it.

#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Traverse all the adjacent nodes of the current node
    for (int neighbor : adjList[node]) {
        // If the neighbor is not visited, recursively call dfs on it
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Create an adjacency list to represent the graph
    vector<vector<int>> adjList(numNodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        // Add the edge to the adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Assuming an undirected graph
    }

    // Create a visited array to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    cout << "DFS traversal starting from node 0: ";
    dfs(0, visited, adjList);

    return 0;
}
