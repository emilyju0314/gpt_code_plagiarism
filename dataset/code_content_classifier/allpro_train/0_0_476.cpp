#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4e5 + 5;
vector<int> adj[MAXN];
int n, centroid[MAXN], sub[MAXN];
bool is_centroid[MAXN];

void dfs(int u, int p) {
    sub[u] = 1;
    bool is_cen = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
        if (sub[v] > n / 2)
            is_cen = false;
    }
    if (n - sub[u] > n / 2)
        is_cen = false;
    is_centroid[u] = is_cen;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        centroid[i] = 0;
        sub[i] = 0;
        is_centroid[i] = false;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int u : adj[1]) {
        if (sub[u] <= n / 2 && n - sub[u] <= n / 2) {
            centroid[1] = 1;
            break;
        }
    }

    for (int u : adj[1]) {
        if (is_centroid[u]) {
            cout << 1 << " ";
        } else {
            int sz = n - sub[u];
            bool can_be_centroid = true;
            for (int v : adj[u]) {
                if (sub[v] > sub[u] && sub[v] > n / 2) {
                    can_be_centroid = false;
                    break;
                }
                if (n - sub[v] > sz && sz > n / 2) {
                    can_be_centroid = false;
                    break;
                }
            }
            if (can_be_centroid) {
                centroid[u] = 1;
            }
            cout << centroid[u] << " ";
        }
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}