#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, revAdj;
vector<int> order, component;
vector<bool> visited;
vector<int> quantifier;
int n, m;
bool hasCycle;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int comp) {
    visited[u] = true;
    component[u] = comp;
    for (int v : revAdj[u]) {
        if (!visited[v]) {
            dfs2(v, comp);
        }
    }
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}

void checkCycle(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            checkCycle(v);
        } else if (component[v] != component[u]) {
            hasCycle = true;
        }
    }
}

int main() {
    cin >> n >> m;
    
    adj.resize(n+1);
    revAdj.resize(n+1);
    visited.assign(n+1, false);
    component.assign(n+1, 0);
    quantifier.assign(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        addEdge(j, k);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    
    visited.assign(n+1, false);
    int comp = 0;
    for (int i = n-1; i >= 0; i--) {
        int u = order[i];
        if (!visited[u]) {
            dfs2(u, comp++);
        }
    }
    
    visited.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            hasCycle = false;
            checkCycle(i);
            if (hasCycle) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    vector<bool> existsCycle(comp, false);
    for (int i = 1; i <= n; i++) {
        if (existsCycle[component[i]]) {
            quantifier[i] = 1; // existential quantifier
        } else {
            quantifier[i] = 2; // universal quantifier
        }
        for (int v : adj[i]) {
            if (component[v] != component[i]) {
                existsCycle[component[v]] = true;
            }
        }
    }
    
    int numUniversal = count(quantifier.begin(), quantifier.end(), 2);
    cout << numUniversal << endl;
    for (int i = 1; i <= n; i++) {
        cout << (quantifier[i] == 2 ? 'A' : 'E');
    }
    cout << endl;
    
    return 0;
}