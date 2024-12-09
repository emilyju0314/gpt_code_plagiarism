#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<vector<int>> adj;
vector<int> computers;
vector<vector<vector<int>>> dp;

int dfs(int v, int computer, int mask) {
    if (dp[v][computer][mask] != -1) {
        return dp[v][computer][mask];
    }

    int result = INF;
    int newMask = mask | (1 << v);

    for (int u : adj[v]) {
        if (!(newMask & (1 << u))) {
            result = min(result, dfs(u, computer, newMask));
        }
    }

    result += (computers[v] != computer ? 1 : 0);

    return dp[v][computer][mask] = result;
}

int main() {
    int n;
    cin >> n;

    computers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> computers[i];
        computers[i]--;
    }

    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int part;
            cin >> part;
            part--;
            adj[part].push_back(i);
        }
    }

    dp.assign(n, vector<vector<int>>(3, vector<int>(1 << n, -1)));

    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            ans = min(ans, dfs(i, j, 1 << i));
        }
    }

    cout << ans << endl;

    return 0;
}