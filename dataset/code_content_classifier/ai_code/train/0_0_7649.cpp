#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> forbidden(m, vector<bool>(m, false));
    for(int i = 0; i < k; i++) {
        char a, b;
        cin >> a >> b;
        forbidden[a - 'a'][b - 'a'] = true;
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    if(n == 1) {
        for(int i = 0; i < m; i++) {
            dp[0][i] = 1;
        }
    } else {
        for(int i = 0; i < m; i++) {
            dp[0][i] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int p = 0; p < m; p++) {
                    dp[i][j] += dp[i-1][p];
                    dp[i][j] %= MOD;
                    if(forbidden[p][j]) {
                        dp[i][j] -= dp[i-1][p];
                        dp[i][j] %= MOD;
                        dp[i][j] += MOD;
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < m; i++) {
        ans += dp[n-1][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}