#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> queries;
int ans[N];
int sum[N];
int parity[N];

void dfs(int u, int parent) {
    for (auto [v, idx] : adj[u]) {
        if (v == parent) continue;
        ans[idx] = sum[u] ^ sum[v] ^ parity[idx];
        dfs(v, u);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            sum[i] = 0;
        }
        queries.clear();
        bool possible = true;

        for (int i = 1; i < n; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            adj[x].push_back({y, i});
            adj[y].push_back({x, i});
            if (v != -1) {
                sum[x] ^= v;
                sum[y] ^= v;
                ans[i] = v;
            } else {
                queries.push_back({x, y});
            }
        }

        for (int i = 1; i <= m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            queries.push_back({a, b});
            parity[queries.size() - 1] = p;
        }

        for (auto [a, b] : queries) {
            sum[a] ^= parity[queries.size() - 1];
            sum[b] ^= parity[queries.size() - 1];
        }

        dfs(1, -1);

        for (int i = 1; i <= n; i++) {
            sum[i] = 0;
        }

        for (int i = 1; i < n; i++) {
            if (ans[i] < 0) {
                possible = false;
                break;
            }
            sum[adj[queries[i - 1].first].size()] ^= ans[i];
            sum[adj[queries[i - 1].second].size()] ^= ans[i];
        }

        if (!possible) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i < n; i++) {
                cout << queries[i - 1].first << " " << queries[i - 1].second << " " << ans[i] << "\n";
            }
        }
    }

    return 0;
}