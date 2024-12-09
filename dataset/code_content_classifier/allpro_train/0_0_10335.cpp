#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> size;
vector<int> ans;

void dfs(int u, int parent) {
    size[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

void solve(int n) {
    size.resize(n, 0);
    dfs(0, -1);

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += min(size[i], n - size[i]);
    }

    for (int i = 1; i < n; i++) {
        ans.push_back({min(size[i], n - size[i]), n - 1});
    }

    cout << total << "\n";
    for (auto p : ans) {
        cout << p[0] << " " << p[1] << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    solve(n);

    return 0;
}