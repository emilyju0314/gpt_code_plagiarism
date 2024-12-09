#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 150001;
vector<int> adj[MAXN];
vector<int> a;
vector<long long> prefixSum, maxPathSum;
long long ans = 0;

void dfs(int u, int par) {
    prefixSum[u] = a[u];
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            prefixSum[u] += prefixSum[v];
        }
    }
}

void calculateMaxPathSum(int u, int par, long long sumPrefix) {
    ans = max(ans, max(a[u] * sumPrefix, a[u] + maxPathSum[u] + sumPrefix));
    for (int v : adj[u]) {
        if (v != par) {
            long long newSum = sumPrefix + prefixSum[u] - prefixSum[v] + a[u];
            calculateMaxPathSum(v, u, newSum);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    a.resize(n);
    prefixSum.resize(n);
    maxPathSum.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dfs(0, -1);
    calculateMaxPathSum(0, -1, 0);

    cout << ans << endl;

    return 0;
}