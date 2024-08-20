#include <bits/stdc++.h>
#define int long long 
using namespace std;
void dfs (vector<vector<int>> &graph, int u, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (auto v : graph[u]) {
        if (!visited[v]) dfs(graph, v, visited);
    }
}

// void dfsStack(vector<vector<int>> &graph, int u, vector<bool> &visited, stack<int> &s) {
//     visited[u] = true;
//     // cout << u << " ";
//     for (auto v : graph[u]) {
//         if (!visited[v]) bfs(graph, v, visited);
//     }
//     s.push(u);
// }
void bfs (vector<vector<int>> &graph, int u, vector<bool> &visited) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    // cout << u << " ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";   
        for (int w : graph[v]) {
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}


// int kosarajuMowa (vector<vector<int>> &graph, int u, vector<vector<int>> &graphTranspose, vector<bool> &visited1, vector<bool> &visited2) {
//     // bfs first, push onto stack, then do reverse dfs calls.
//     stack<int> s;
//     int graphSize = graph.size();

//     for (int i = 0; i < graphSize; i++) {
//         dfsStack(graph, i, visited1, s);
//     }

//     int res = 0;
//     while (!s.empty()) {
//         int v = s.top();
//         s.pop();
//         if (!visited2[v]) {
//             dfs(graphTranspose, v, visited2);
//             res++;
//         }
//     }
//     return res;

//     // reverse dfs

// }
signed main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph (n + 1);
    vector<vector<int>> graphTranspose (n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        graphTranspose[v].push_back(u);
    }
    vector<bool> visited(n+1, false);
    vector<bool> visited1(n+1, false);
    vector<bool> visited2(n+1, false);
    bfs(graph, 0, visited); 
    printf("\nNow DFS\n");
    dfs(graph, 0, visited1);
    
}