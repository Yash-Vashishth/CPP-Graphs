/*
You have been given an undirected graph with 'N' vertices and 'M' edges. 
The vertices are labelled from 1 to 'N'.Your task is to find if the graph 
contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing 
the edges only once is called a cycle.
*/ 
#include <iostream>
#include <vector>
using namespace std;

bool dfsUtil(vector<vector<int>>& graph, int node, vector<bool>& visited, int parent) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfsUtil(graph, neighbor, visited, node)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}
bool detectCycle(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsUtil(graph, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (detectCycle(graph, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
