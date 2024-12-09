#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2*1e5 + 5;

vector<int> adj[N];
int lights[N], ans[N];

void dfs(int u, int p, int x) {
    ans[u] = x;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (lights[v] != -1) {
            dfs(v, u, lights[v]);
        } else {
            dfs(v, u, x ^ 1);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            adj[x].push_back(y);
            adj[y].push_back(x);
            lights[i] = v;
        }

        dfs(1, 0, 0);

        bool consistent = true;
        for (int i = 1; i <= n; i++) {
            if (ans[i] < 0 || ans[i] > 1) {
                consistent = false;
                break;
            }
        }

        if (!consistent) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 1; i < n; i++) {
                cout << i << " " << adj[i][0] << " " << ans[adj[i][0]] << endl;
            }
        }
    }

    return 0;
}