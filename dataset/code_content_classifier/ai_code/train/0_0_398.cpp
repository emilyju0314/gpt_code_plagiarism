#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> obstacles(3, vector<int>(m+1));
    for(int i = 0; i < n; i++) {
        int a, l, r;
        cin >> a >> l >> r;
        for(int j = l; j <= r; j++) {
            obstacles[a-1][j] = 1;
        }
    }

    vector<vector<int>> dp(3, vector<int>(m+1));
    dp[1][1] = 1;

    for(int j = 2; j <= m; j++) {
        for(int i = 0; i < 3; i++) {
            if(obstacles[i][j]) continue;

            for(int k = -1; k <= 1; k++) {
                int prev_i = i + k;
                if(prev_i < 0 || prev_i >= 3) continue;

                dp[i][j] = (dp[i][j] + dp[prev_i][j-1]) % MOD;
            }
        }
    }

    int ans = dp[1][m];
    cout << ans << endl;

    return 0;
}