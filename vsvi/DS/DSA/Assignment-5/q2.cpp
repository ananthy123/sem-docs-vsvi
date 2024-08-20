#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
//Dijkstra basic idea
#define int long long
#define INF INT_MAX

// now understand that we need to implement using pairs 
priority_queue <pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;
void dijkstra (vector<vector<pair<int,int>>> &graph, int source, vector<int> &distance, vector<int> &freq) {
    int n = graph.size();
    distance.assign(n, INF);
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        //condition to continue
        if (dist_u > distance[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (distance[u] + w == distance[v]) {
                freq[v]++;
            }
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
                freq[v] = 1;
            }
        }
    }
}



signed main () {
    int n, m, fibers;
    cin >> n >> m >> fibers;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<pair<int, int>> fiberVector(fibers);
    vector <int> freq (n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
            if (u == v) continue; //handle self loops
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
    }
    for (int i = 0; i < fibers; i++) {
        int v, w;
        cin >> v >> w;
        graph[1].push_back({v, w});
        graph[v].push_back({1, w});
        fiberVector[i] = {v, w};
        //these are the fibers
    }


    int source = 1;
    vector<int> distance(n + 1);
    dijkstra(graph, source, distance, freq);

    // cout << "Shortest distances from source " << source << ":\n";
    // for (int i = 1; i <= n; ++i) {
    //     cout << "Vertex " << i << ": ";
    //     if (distance[i] == INF)
    //         cout << "INF\n";
    //     else
    //         cout << distance[i] << "\n";
    // }
    int csls = 0;
    // for (int i = 1; i < freq.size(); i++) {
    //     cout << "Frequency at " << i << " is " << freq[i] << endl;
    // }
    for (int i = 0; i < fibers; i++) {
        int dest = fiberVector[i].first;
        int fiberDistance = fiberVector[i].second;
        // Do two things, check if fiber length is actually worse
        if (fiberDistance > distance[dest]) {
            csls++;
        }

        else if (fiberDistance == distance[dest]) {
            if (freq[dest] >= 2) {
                csls++;
                freq[dest]--;
            }
        }
    }
    cout << csls << "\n";
}