#include <iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

void bfs(vector<int> G[], int n, int src) {
    bool visited[n+1] = {false};
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

void printDFS(vector<int> G[], bool visited[], int n, int src) {
    cout << src << " ";
    visited[src] = true;
    for(auto i : G[src])
        if(!visited[i])
            printDFS(G, visited, n, i);
}

void dfs(vector<int> G[], int n, int src) {
    if(src < 1 || src > n) {
        cout << "DFS Source Vertex Invalid\n";
        return;
    }
    bool visited[n+1] = {false};
    printDFS(G, visited, n, src); cout << "\n";
}

// Number of Disconected Components in the graph


void dfsForComponents(vector<int> G[], bool visited[], int n, int src) {    // It is same as printDFS except cout statement
    visited[src] = true;
    for(auto i : G[src])
        if(!visited[i])
            dfsForComponents(G, visited, n, i);
}
int numberOfComponents(vector<int> G[], int n) {
    bool visited[n+1] = {false};
    int count = 0;
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            count++;
            dfsForComponents(G, visited, n, i);
        }
    }
    return count;
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
    // dfs(G, n, 1);
    cout << numberOfComponents(G, n);

    return 0;
}