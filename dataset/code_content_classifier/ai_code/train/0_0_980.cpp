#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 505;
const int MAXMOD = 1e9 + 7;

int main() {
    int n, mod;
    cin >> n >> mod;

    vector<vector<int>> dp(n+1, vector<int>(n*n/2+1));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = i*(i-1)/2; j <= n*(n-1)/2; j++) {
            for(int k = 0; k <= min((i-1)*i/2, j); k++) {
                dp[i][j] = (dp[i][j] + 1LL * dp[i-1][j-k] * dp[i-1][j-k] % mod) % mod;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n*(n-1)/2; i++) {
        ans = (ans + 1LL * dp[n][i] * (n*(n-1)/2 - i) % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}