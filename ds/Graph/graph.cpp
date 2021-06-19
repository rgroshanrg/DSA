#include <iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

void bfs(vector<int> G[], int n, int src) {
    bool visited[n] = {false};
    if(src < 1 || src > n) {
        cout << "BFS Source Vertex Invalid\n";
        return;
    }
    queue<int> Q;
    Q.push(src);
    visited[src] = true;
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        cout << node << " ";
        for(auto i : G[node]) {
            if(!visited[i]) {
                Q.push(i);
                visited[i] = true;
            }
        }
    } cout << "\n";
}

int main() {
    int n = 6;  //number of vertices
    int e = 8;  //number of edges
    vector<int> G[n+1];   //Adjacency List of Undirected Graph

    // Builting vector pairs of edges
    vector<pair<int, int>> edges(e);
    edges = {
        { 1, 2 },
        { 1, 6 },
        { 2, 3 },
        { 2, 5 },
        { 3, 6 },
        { 3, 4 },
        { 4, 5 },
        { 5, 6 }
    };

    // Adding Edges e times in Graph G
    for(int i = 0; i < e; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(G, n, 1);

    return 0;
}