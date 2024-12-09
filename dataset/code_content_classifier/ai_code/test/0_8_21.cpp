#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n, m, k, p;
int dp[101][101][101]; // dp[n][m][k] stores the number of permutations of length n with exactly m good numbers with p maximums

int solve(int len, int maxs, int goods) {
    if(len == 0) {
        if(goods == 0 && maxs == 0) return 1;
        return 0;
    }

    if(dp[len][maxs][goods] != -1) return dp[len][maxs][goods];

    int res = 0;

    // 1. Don't add a maximum
    res += solve(len - 1, maxs, goods);

    // 2. Add a maximum
    res += solve(len - 1, max(len - 1, maxs), goods - (maxs == len - 1));

    return dp[len][maxs][goods] = res % MOD;
}

int main() {
    cin >> n >> m >> k >> p;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int l = 0; l <= n; l++) {
                dp[i][j][l] = -1;
            }
        }
    }

    int ans = 0;

    // Since there are k good numbers, there must be at least k maximums
    for(int i = k; i <= n; i++) {
        ans += solve(n, i, m) % MOD;
    }

    cout << ans % p << endl;

    return 0;
}