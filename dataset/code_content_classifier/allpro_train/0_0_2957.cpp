#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, INF)));

    for (int i = 1; i < n; i++) {
        dp[0][i][1] = cost[0][i];
    }

    for (int c = 2; c <= k; c += 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int x = 0; x < n; x++) {
                    if (i != j && j != x && x != i) {
                        dp[i][j][c] = min(dp[i][j][c], dp[i][x][c-1] + cost[x][j]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[i][0][k]);
    }

    cout << ans << endl;

    return 0;
}