#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> ripe_fruits;
int max_juice = 0;

void dfs(int node, int parent) {
    if (ripe_fruits[node] > 0) {
        max_juice += ripe_fruits[node];
    }
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    adj.resize(n + 1);
    ripe_fruits.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int p_i;
        cin >> p_i;
        adj[p_i].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int v, d, w;
        cin >> v >> d >> w;
        if (d <= k) {
            ripe_fruits[v] = max(ripe_fruits[v], w);
        }
    }

    for (int day = 1; day <= k; day++) {
        max_juice = 0;
        dfs(1, -1);
        cout << max_juice << endl;
    }

    return 0;
}