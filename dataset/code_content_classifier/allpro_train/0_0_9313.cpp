#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int max_depth = 0;

void dfs(int v, int depth) {
    visited[v] = true;
    max_depth = max(max_depth, depth);
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u, depth + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    visited.resize(n+1, false);

    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cout << max_depth << endl;

    return 0;
}