#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
int t = 0;
int w = 1;

void dfs(int v, int p, int len, unordered_set<int>& vertices) {
    visited[v] = true;
    vertices.insert(v);

    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, v, len + 1, vertices);
        } else if (u != p && vertices.count(u) > 0 && len % 2 == 0) {
            t++;
        }
    }
}

int main() {
    cin >> n >> m;
    
    adj.resize(n+1);
    visited.resize(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            unordered_set<int> vertices;
            dfs(i, -1, 0, vertices);
            if (vertices.size() % 2 == 0) {
                w *= 2;
            }
        }
    }

    cout << t << " " << w << endl;

    return 0;
}