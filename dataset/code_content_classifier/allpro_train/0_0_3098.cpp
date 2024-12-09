#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }

    int dp[1 << M][N];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
        dp[0][i] = 1;
    }

    for (int mask = 1; mask < (1 << M); mask++) {
        for (int u = 0; u < N; u++) {
            for (int i = 0; i < M; i++) {
                int x = edges[i].first - 1;
                int y = edges[i].second - 1;

                if ((mask & (1 << i)) && u == x) {
                    dp[mask][y] = (dp[mask][y] + dp[mask ^ (1 << i)][u]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << M); mask++) {
        ans = (ans + dp[mask][1]) % MOD;
    }

    cout << ans << endl;

    return 0;
}