#include <iostream>
#include <vector>
using namespace std;

int dp[101][101][101];
int n, m, k, p;

int solve(int pos, int rem, int max_val) {
    if (pos == n) {
        if (rem == 0 && max_val != 0) return 1;
        return 0;
    }

    if (dp[pos][rem][max_val] != -1) return dp[pos][rem][max_val];

    int res = solve(pos + 1, rem, max_val);
    if (max_val != 0) {
        res = (res + solve(pos + 1, rem - 1, max_val - 1)) % p;
    }
    res = (res + solve(pos + 1, rem, k)) % p;

    return dp[pos][rem][max_val] = res;
}

int main() {
    cin >> n >> m >> k >> p;

    memset(dp, -1, sizeof(dp));

    cout << solve(0, m, k) << endl;

    return 0;
}