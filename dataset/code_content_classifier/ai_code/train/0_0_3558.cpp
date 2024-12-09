#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(k+1, vector<double>(n, 0.0)));
    dp[0][k][0] = 1.0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int k = 0; k < n; k++) {
                if(dp[i][j][k] == 0.0) {
                    continue;
                }
                dp[i+1][j][k] += dp[i][j][k];

                if(a[i] == 0) {
                    dp[i+1][j][k] += dp[i][j][k] / n;
                } else {
                    dp[i+1][j-1][k] += dp[i][j][k] / n;
                }

                if(j > 0) {
                    if(a[i] == 0) {
                        dp[i+1][j][k+1] += dp[i][j][k] / n;
                    } else {
                        dp[i+1][j-1][k+1] += dp[i][j][k] / n;
                    }
                }
            }
        }
    }

    double ans = 0.0;
    for(int i = 0; i < n; i++) {
        ans += dp[n][0][i];
    }

    int Q = 1;
    for(int i = 1; i <= k; i++) {
        Q = (Q * n) % MOD;
    }

    int invQ = 1;
    for(int i = 1; i <= MOD - 2; i++) {
        invQ = (invQ * Q) % MOD;
    }

    int P = round(ans * Q) % MOD;

    if(P == 0) {
        cout << 0 << endl;
    } else {
        cout << (P * invQ) % MOD << endl;
    }

    return 0;
}