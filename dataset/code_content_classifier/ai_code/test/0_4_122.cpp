#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[maxn];
vector<int> ans;
int lights[maxn], visited[maxn];
int is_odd[maxn], edge_used[maxn];
int odd_count, total_count;

int dfs(int u, int p, int found_xor) {
    visited[u] = 1;

    int xor_val = 0;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        xor_val = dfs(v.first, u, v.second);
    }

    if (p != -1) {
        if (lights[p] != -1) xor_val = lights[p];
        if (found_xor != -1) xor_val = found_xor;
    }

    if (lights[u] == -1) {
        lights[u] = xor_val;
        ans.push_back(u);
        ans.push_back(p);
        ans.push_back(xor_val);
    } else {
        if (lights[u] != xor_val) {
            cout << "NO" << endl;
            exit(0);
        }
    }

    return lights[u];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        ans.clear();
        memset(lights, -1, sizeof(lights));
        memset(visited, 0, sizeof(visited));
        memset(is_odd, -1, sizeof(is_odd));
        memset(edge_used, 0, sizeof(edge_used));
        odd_count = 0;
        total_count = 0;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            adj[x].push_back({y, v});
            adj[y].push_back({x, v});
        }

        for (int i = 1; i <= m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            int found_xor = -1;
            if (lights[a] != -1) found_xor = lights[a];
            if (lights[b] != -1) found_xor = lights[b];

            if (found_xor == -1 && is_odd[p] == -1) {
                is_odd[p] = total_count;
                total_count++;
            } else {
                found_xor = found_xor == -1 ? lights[a] : found_xor;
            }

            dfs(a, -1, found_xor);

            if (found_xor != -1) {
                int xor_val = found_xor;
                if (edge_used[xor_val]) {
                    cout << "NO" << endl;
                    continue;
                }
                edge_used[xor_val] = 1;
                int one_count = __builtin_popcount(xor_val);
                if (p == one_count % 2) continue;
                cout << "NO" << endl;
            } else {
                odd_count += p;
            }
        }

        if (odd_count % 2 == 0 && total_count) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n - 1; i++) {
                cout << ans[i * 3] << " " << adj[ans[i * 3]].back().first << " " << ans[i * 3 + 2] << endl;
                adj[ans[i * 3]].pop_back();
            }
        }
    }

    return 0;
}