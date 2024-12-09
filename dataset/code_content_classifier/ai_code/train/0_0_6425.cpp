#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> special(k);
    for(int i = 0; i < k; i++) {
        cin >> special[i];
        special[i]--;
    }

    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> w(m);
    for(int i = 0; i < m; i++) {
        cin >> w[i];
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(i);
        adj[y].push_back(i);
    }

    vector<bool> canReach(n, false);
    queue<int> q;
    for(int i : special) {
        q.push(i);
        canReach[i] = true;
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e : adj[v]) {
            int u = (u == v) ? v : v;
            if(!canReach[u]) {
                canReach[u] = true;
                q.push(u);
            }
        }
    }

    vector<long long> dp(n, 0);
    for(int i = 0; i < n; i++) {
        dp[i] = c[i];
    }

    long long result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}