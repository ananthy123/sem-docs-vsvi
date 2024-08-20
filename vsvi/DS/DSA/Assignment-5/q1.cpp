#include <bits/stdc++.h>
using namespace std;

void dfs (int u, vector<vector<int>> &adjList, vector<int> &visited) {
    visited[u] = true;
    for (int v : adjList[u]) if (!visited[v]) dfs (v, adjList, visited);
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n+1);
    for (int i = 0; i < m; i++) {
        int src, dest;
        cin >> src >> dest;
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    vector<int> visited (n+1, false);
    vector<int> finalCalls;
    int totalComponents = 0;
    for (int i = 1; i <=n; i++) {
        if (!visited[i]) {
            dfs (i, adjList, visited);
            finalCalls.push_back(i);
            totalComponents++;
        }
    }
    cout << totalComponents - 1 << endl;
    for (int i = 0; i < finalCalls.size() - 1; i++) {
        cout << finalCalls[i] << " " << finalCalls[i+1] << "\n";
    }
    return 0;
}