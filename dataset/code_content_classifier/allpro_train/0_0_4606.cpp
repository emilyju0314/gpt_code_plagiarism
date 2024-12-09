#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int visited[100005];

vector<int> independentSet;
vector<int> cycle;
int k;

void dfs(int v, int p, int depth) {
    visited[v] = 1;
    
    if (depth >= (k + 1) / 2) {
        if (independentSet.size() == 0) {
            for (int i = 1; i <= depth; i += 2) {
                independentSet.push_back(cycle[i]);
            }
        }
        return;
    }
    
    cycle.push_back(v);
    for (int u : adj[v]) {
        if (u == p) continue;
        if (visited[u]) {
            if (depth <= k) {
                int idx = 0;
                while (cycle[idx] != u) idx++;
                cout << 2 << endl;
                cout << depth - idx << endl;
                for (int i = idx; i < depth; i++) {
                    cout << cycle[i] << " ";
                }
                cout << u << endl;
                exit(0);
            }
        } else dfs(u, v, depth + 1);
    }
    cycle.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1, 1);
    
    cout << 1 << endl;
    for (int i = 0; i < independentSet.size(); i++) {
        cout << independentSet[i] << " ";
    }
    
    return 0;
}