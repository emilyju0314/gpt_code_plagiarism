#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_V = 10000;
const int MAX_E = 30000;

vector<int> adj[MAX_V]; // Adjacency list representation of the graph
vector<int> rev_adj[MAX_V]; // Reverse adjacency list for the reversed graph
bool visited[MAX_V];
stack<int> order;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    order.push(u);
}

void dfs_reverse(int u, vector<int>& component, int index) {
    visited[u] = true;
    component[u] = index;
    for (int v : rev_adj[u]) {
        if (!visited[v]) {
            dfs_reverse(v, component, index);
        }
    }
}

int main() {
    int V, E, Q;
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
        rev_adj[t].push_back(s);
    }
    
    // Kosaraju's Algorithm to find strongly connected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    fill(visited, visited+V, false);
    int index = 1;
    vector<int> component(V, 0);
    
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!visited[u]) {
            dfs_reverse(u, component, index);
            index++;
        }
    }
    
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        if (component[u] == component[v]) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}