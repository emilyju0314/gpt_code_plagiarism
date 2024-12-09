#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
vector<int> tree[MAXN];
vector<pair<int, int>> updates;
vector<bool> good_vertex;
vector<int> parent;
vector<int> subtree_size;

void dfs(int v, int p) {
    parent[v] = p;
    subtree_size[v] = 1;
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

bool is_good(int v) {
    if (subtree_size[v] == n) return false; // The entire tree T cannot be a subtree rooted at v
    for (int u : tree[v]) {
        if (u != parent[v] && subtree_size[u] > n / 2) return false; // Subtree rooted at u is too large
    }
    return true;
}

void solve() {
    cin >> n >> q;
    parent.resize(n + 1);
    subtree_size.resize(n + 1);
    good_vertex.resize(n + 1);
    
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        good_vertex[i] = is_good(i);
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (parent[v] == u) swap(u, v);
        good_vertex[u] = good_vertex[u] || is_good(u);
        for (int j = 1; j <= n; j++) {
            if (parent[j] == u) {
                good_vertex[j] = good_vertex[j] || is_good(j);
            }
        }
        cout << count(good_vertex.begin() + 1, good_vertex.end(), true) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}