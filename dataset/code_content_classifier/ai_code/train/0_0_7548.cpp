#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MOD 998244353

using namespace std;

int dp[3005][3005], ans;
string S, T;

int main() {
    cin >> S >> T;
    int n = S.size();
    int m = T.size();

    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j-1] + (S[i-1] == T[j-1]) * dp[i-1][j]) % MOD;
        }
    }

    for(int i = m; i <= n; i++) {
        ans = (ans + dp[i][m]) % MOD;
    }

    cout << ans << endl;

    return 0;
}