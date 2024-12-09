#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3 * 1e5 + 5;
vector<int> adj[MAXN], soroush_tree[MAXN], keshi_tree[MAXN];
vector<int> s_depth(MAXN), k_depth(MAXN), l_depth(MAXN), r_depth(MAXN);
int n;

void dfs_soroush(int v, int p) {
    s_depth[v] = (p == -1) ? 0 : s_depth[p] + 1;
    for (int u : soroush_tree[v]) {
        if (u != p) {
            dfs_soroush(u, v);
        }
    }
}

void dfs_keshi(int v, int p) {
    k_depth[v] = (p == -1) ? 0 : k_depth[p] + 1;
    for (int u : keshi_tree[v]) {
        if (u != p) {
            dfs_keshi(u, v);
        }
    }
}

void dfs(int v, int p) {
    l_depth[v] = (p == -1) ? 0 : l_depth[p] + 1;
    r_depth[v] = (p == -1) ? 0 : r_depth[p] + 1;
    int l = 0, r = 0;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            if (s_depth[u] > s_depth[l]) {
                l = u;
            }
            if (k_depth[u] > k_depth[r]) {
                r = u;
            }
        }
    }
    if (l + r == 0) {
        return;
    }
    int length = l_depth[l] + r_depth[r] + 2;
    if (l != 0 && r != 0 && s_depth[l] < s_depth[r]) {
        length = max(length, r_depth[r]);
    }
    cout << length << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            soroush_tree[i].clear();
            keshi_tree[i].clear();
        }

        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            soroush_tree[p].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            keshi_tree[p].push_back(i);
        }

        dfs_soroush(1, -1);
        dfs_keshi(1, -1);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < soroush_tree[i].size(); j++) {
                adj[i].push_back(soroush_tree[i][j]);
            }
        }

        dfs(1, -1);
        cout << "\n";
    }

    return 0;
}