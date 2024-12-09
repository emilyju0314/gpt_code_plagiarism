#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<vector<pair<int, int>>> adj;
vector<int> weights;
vector<int> subtreeSizes;
vector<long long> ans;

void dfs(int u, int p) {
    subtreeSizes[u] = 1;
    for (auto edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            dfs(v, u);
            subtreeSizes[u] += subtreeSizes[v];
            ans[0] += min(subtreeSizes[v], n - subtreeSizes[v]) * 1LL * w;
        }
    }
}

void update(int u, int p, int x) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            ans[x] = ans[x - 1];
            ans[x] -= min(subtreeSizes[v], n - subtreeSizes[v]) * 1LL * w;
            subtreeSizes[u] -= subtreeSizes[v];
            subtreeSizes[v] += subtreeSizes[u];
            ans[x] += min(subtreeSizes[v], n - subtreeSizes[v]) * 1LL * w;
            update(v, u, x);
            subtreeSizes[v] -= subtreeSizes[u];
            subtreeSizes[u] += subtreeSizes[v];
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    subtreeSizes.resize(n);
    weights.resize(n - 1);
    ans.assign(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        weights[i] = c;
    }

    dfs(0, -1);

    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1];
        for (int j = 0; j < n - 1 && j < i; j++) {
            set<int> idx;
            int u = 0;
            long long sum = 0;
            while (idx.size() < i - j) {
                int maxEdgeIdx = -1;
                for (int k = 0; k < adj[u].size(); k++) {
                    int v = adj[u][k].first;
                    if (v != 0 && !idx.count(k) && (maxEdgeIdx == -1 || weights[k] > weights[maxEdgeIdx])) {
                        maxEdgeIdx = k;
                    }
                }
                if (maxEdgeIdx == -1) break;
                idx.insert(maxEdgeIdx);
                sum += weights[maxEdgeIdx];
                u = adj[u][maxEdgeIdx].first;
            }
            ans[i] = min(ans[i], ans[i - 1 - j] + sum);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}