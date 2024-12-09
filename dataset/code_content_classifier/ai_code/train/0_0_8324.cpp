#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 5;
vector<int> adj[MAX_N];
int a[MAX_N], b[MAX_N], subtree_max[MAX_N], ans[MAX_N];
int start_time[MAX_N], end_time[MAX_N], timer = 0;
vector<pair<int, int>> queries[MAX_N];

void dfs(int u) {
    start_time[u] = timer++;
    subtree_max[u] = a[u] * b[u];
    for (int v : adj[u]) {
        dfs(v);
        subtree_max[u] = max(subtree_max[u], subtree_max[v]);
    }
    end_time[u] = timer++;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    dfs(1);

    for (int i = 0; i < q; i++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            int x;
            cin >> x;
            a[v] += x;
            for (int j = start_time[v]; j < end_time[v]; j++) {
                ans[j] += x * b[v];
            }
        } else {
            cout << subtree_max[v] << endl;
        }
    }

    return 0;
}