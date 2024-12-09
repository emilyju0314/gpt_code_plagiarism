#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int n;
long long T;
vector<int> cookies(MAX_N), eat_time(MAX_N), parent(MAX_N), edge_time(MAX_N);
vector<vector<int>> children(MAX_N);
vector<vector<long long>> dp(MAX_N, vector<long long>(MAX_N));

void dfs(int v) {
    for (int u : children[v]) {
        dfs(u);
        for (int t = T; t >= edge_time[u]; t--) {
            dp[v][t] = max(dp[v][t], dp[u][t - edge_time[u]]);
        }
    }

    for (int t = T; t >= edge_time[v]; t--) {
        dp[v][t] = max(dp[v][t], dp[v][t - edge_time[v]] + cookies[v] - t / eat_time[v]);
    }
}

int main() {
    cin >> n >> T;

    for (int i = 1; i <= n; i++) {
        cin >> cookies[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> eat_time[i];
    }

    for (int i = 2; i <= n; i++) {
        int p, l;
        cin >> p >> l;
        children[p].push_back(i);
        parent[i] = p;
        edge_time[i] = l;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }

    dfs(1);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }

    cout << ans << endl;

    return 0;
}