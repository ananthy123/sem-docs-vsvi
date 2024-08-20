//minimum spanning tree

//we have to join all the vertices, with minimum possible no. edges
//if no. of vertices is v, no. of edgtes is v-1
//graph must be single component


//in primes algo, we will find the minimum weight vertex for a respecttive parent, 
//and hen join the parent with that vertex, 
//also we will traverse all its()parent) linked nodes, and set there minimum distance. 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//#define INT_MAX 1000000;

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector <int> lIndex(size, 0);
        vector <int> rIndex(size, 0);

        stack<int> s1;
        stack<int> s2;
        return 10;

       }

int find_min_distance_vertex(vector<bool>visited, vector<int>dist, int n){
    int minn = INT_MAX;
    int idx;
    for(int i=0;i < n ; i++){
        if(visited[i] == false && dist[i] < minn){
            minn = dist[i];
            idx = i;
        }
    }
    return idx;
}

void find_min_spanning_tree(int n,vector<int>&parent, vector<bool>visited, vector<int>dist, vector<vector<int>>v){

    int curr_parent = -1;
    dist[0] = 0;
    parent[0] = -1;
    //no_of edgrs will be n-1.
    for(int i=0;i<n-1; i++){

        int idx = find_min_distance_vertex(visited, dist,n);
        visited[idx] = true;

        curr_parent = idx;
        for(int j=0;j<n; j++){
            if(v[idx][j] !=0 && visited[j]==false && v[idx][j] < dist[j]){
                v[idx][j] = dist[j];
                parent[j] = idx;
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>>v(n, vector<int>(n,0));
    //matrix to store all the edge weigths from i->j or j->i
    for(int i=0;i<n; i++){
        int a,b,w;
        cin>>a>>b>>w;

        v[a][b] = w;
        v[b][a] = w;
    }

    //parent array, visited_array

    vector<int>parent(n,-1);//ans vector.
    vector<bool>visited(n,false);

    //array to store the maximum weight
    vector<int>dist(n, INT_MAX);
    find_min_spanning_tree(n, parent , visited , dist,v);
    //for min_spanning rtree all the vertices must be connected.

    for( int i=0;i<n; i++){
        cout<<i<<" -> "<<parent[i]<<"\n";
    }
}