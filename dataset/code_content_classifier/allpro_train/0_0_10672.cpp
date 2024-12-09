#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if (k == 1) {
        cout << 2 << endl;
        for (int i = 0; i < n; i++) {
            cout << i+1 << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].size() < k - 1)
            continue;

        set<int> nbs;
        for (int j : adj[i]) {
            if (adj[j].size() >= k - 1)
                nbs.insert(j);
        }

        nbs.insert(i);
        bool found = false;
        for (int v : nbs) {
            bool valid = true;
            for (int u : nbs) {
                if (u == v)
                    continue;
                if (adj[u].find(v) == adj[u].end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << 2 << endl;
                for (int u : nbs) {
                    cout << u + 1<< " ";
                }
                cout << endl;
                found = true;
                break;
            }
        }

        if (found)
            return;
    }

    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}