#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> pleasantness;
vector<long long> chloe_dp, vladik_dp;

void dfs(int node, int parent) {
    long long chloe_sum = 0, vladik_sum = 0;
    bool chloe_possible = false;

    for (int child : adj[node]) {
        if (child == parent) continue;
        
        dfs(child, node);

        if (vladik_dp[child] > 0) {
            vladik_sum += vladik_dp[child];
        } else {
            chloe_possible = true;
            chloe_sum += chloe_dp[child];
        }
    }

    chloe_dp[node] = chloe_sum + pleasantness[node];
    vladik_dp[node] = max(chloe_sum, vladik_sum);

    if (!chloe_possible) {
        chloe_dp[node] = -1e18; // A large negative value to indicate impossibility
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    pleasantness.resize(n);
    chloe_dp.resize(n);
    vladik_dp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pleasantness[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    if (vladik_dp[0] <= 0) {
        cout << "Impossible" << endl;
    } else {
        cout << vladik_dp[0] << endl;
    }

    return 0;
}