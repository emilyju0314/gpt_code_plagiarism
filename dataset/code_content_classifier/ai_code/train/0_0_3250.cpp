#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> universities;
vector<int> subtree_size;
long long total_distance = 0;

void dfs(int v, int p = -1) {
    subtree_size[v] = (find(universities.begin(), universities.end(), v) != universities.end());
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
        total_distance += min(subtree_size[u], 2 * k - subtree_size[u]);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    universities.resize(2 * k);
    for (int i = 0; i < 2 * k; i++) {
        cin >> universities[i];
    }

    adj.resize(n + 1);
    subtree_size.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    cout << total_distance << endl;

    return 0;
}