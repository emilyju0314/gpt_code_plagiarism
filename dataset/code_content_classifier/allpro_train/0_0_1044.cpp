#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, q;
vector<long long> values;
vector<vector<pair<int, int>>> tree;
vector<vector<pair<int, long long>>> paths;
vector<bool> visited;

void dfs(int v, int parent, long long value) {
    visited[v] = true;
    for (auto neighbor : tree[v]) {
        if (neighbor.first != parent) {
            dfs(neighbor.first, v, value + values[neighbor.first]);
            paths[v].push_back({neighbor.first, values[neighbor.first] - neighbor.second});
            paths[v].push_back({neighbor.first, -2LL * neighbor.second});
            paths[v].push_back({neighbor.first, 0});
        }
    }
}

long long findMaxProfit(int start, int end) {
    map<int, long long> dp;
    for (auto p : paths[start]) {
        dp[p.first] = p.second;
    }

    long long result = values[start];
    for (auto p : paths[end]) {
        result = max(result, dp[p.first] + p.second);
    }

    return result;
}

int main() {
    cin >> n >> q;
    values.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    tree.resize(n);
    paths.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        tree[a].push_back({b, w});
        tree[b].push_back({a, w});
    }

    dfs(0, -1, values[0]);

    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        start--; end--;
        cout << findMaxProfit(start, end) << endl;
    }

    return 0;
}