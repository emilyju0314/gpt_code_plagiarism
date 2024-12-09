#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> beavers;
vector<long long> dp;
int start_vertex;

void dfs(int u, int parent) {
    dp[u] = beavers[u];
    for (int v : tree[u]) {
        if (v != parent) {
            dfs(v, u);
            dp[u] += max(0LL, dp[v]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    beavers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> beavers[i];
    }
    tree.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dp.resize(n);
    cin >> start_vertex;
    start_vertex--;

    dfs(start_vertex, -1);

    cout << dp[start_vertex] << endl;

    return 0;
}