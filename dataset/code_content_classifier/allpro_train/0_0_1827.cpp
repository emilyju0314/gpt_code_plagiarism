#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> op;
vector<vector<int>> adj;
vector<int> dpMax, dpMin;

void dfs(int u) {
    if(adj[u].size() == 0) {
        dpMax[u] = 1;
        dpMin[u] = 1;
        return;
    }

    dpMax[u] = op[u] == 1 ? 0 : 1e6;
    dpMin[u] = op[u] == 0 ? 0 : 1e6;

    for(int v : adj[u]) {
        dfs(v);
        if(op[u] == 1) {
            dpMax[u] = max(dpMax[u], dpMax[v]);
            dpMin[u] = max(dpMin[u], dpMin[v]);
        } else {
            dpMax[u] = min(dpMax[u], dpMax[v]);
            dpMin[u] = min(dpMin[u], dpMin[v]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    op.resize(n+1);
    adj.resize(n+1);
    dpMax.resize(n+1);
    dpMin.resize(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> op[i];
    }

    for(int i = 2; i <= n; i++) {
        int f;
        cin >> f;
        adj[f].push_back(i);
    }

    dfs(1);

    cout << dpMax[1] << endl;

    return 0;
}