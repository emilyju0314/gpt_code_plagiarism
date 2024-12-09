#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, b, mod;
vector<int> a;
int dp[505][505][505];
int solve(int i, int j, int k) {
    if (j == 0 && k == 0) {
        return 1;
    }
    if (i == 0 || j < 0 || k < 0) {
        return 0;
    }
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    dp[i][j][k] = (solve(i - 1, j, k) + solve(i - 1, j - 1, k - a[i])) % mod;
    return dp[i][j][k];
}

int main() {
    cin >> n >> m >> b >> mod;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i <= b; i++) {
        ans = (ans + solve(n, m, i)) % mod;
    }
    cout << ans << endl;
    return 0;
}