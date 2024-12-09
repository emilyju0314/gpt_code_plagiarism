#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> depth;

void dfs(int u, int p, int d) {
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N + 1);
    depth.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    int max_depth = *max_element(depth.begin(), depth.end());

    cout << max_depth << endl;

    return 0;
}