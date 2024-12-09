#include <bits/stdc++.h>

using namespace std;

const int INF = 2 * 1e9;
const int MAX_N = 100;
const int MAX_V = 100;
int n, W, v[MAX_N], w[MAX_N], dp[MAX_N + 1][MAX_N * MAX_V + 1];

int main(void) {
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];

    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            if (j < v[i]) dp[i + 1][j] = dp[i][j];
            else dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    
    int res;
    for (int i = 0; i <= MAX_N * MAX_V; i++)
        if (dp[n][i] <= W) res = i;
    
    cout << res << endl;

    return 0;
}
