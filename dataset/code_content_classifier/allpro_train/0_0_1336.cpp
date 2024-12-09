#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007

using namespace std;

int main() {
    int n, q, t;
    cin >> n >> q >> t;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<pair<int, int>> conditions(q);
    for(int i = 0; i < q; i++) {
        cin >> conditions[i].first >> conditions[i].second;
    }

    int dp[n+1][t+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= t; j++) {
            for(int k = 0; k <= j && k <= t/coins[i]; k++) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j-k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= t; j++) {
        bool valid = true;
        for(auto condition : conditions) {
            if(dp[condition.first][j] <= dp[condition.second][j]) {
                valid = false;
                break;
            }
        }
        if(valid) {
            ans = (ans + dp[n][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}