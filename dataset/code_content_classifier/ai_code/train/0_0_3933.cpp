#include <iostream>
#include <vector>

const int MOD = 1000000007;

int dp[55][55][55][55];
int n, k;

int solve(int v, int b1, int b2, int m) {
    if (v == n) {
        return m == k;
    }

    if (dp[v][b1][b2][m] != -1) {
        return dp[v][b1][b2][m];
    }

    int ans = 0;

    // Case 1: Create a new branch with one child
    if (b1 < 2) {
        ans += solve(v+1, b1+1, b2, m);
        ans %= MOD;
    }

    // Case 2: Create a new branch with two children
    if (b1 > 0 && b2 < 2) {
        ans += solve(v+1, b1, b2+1, m);
        ans %= MOD;
    }

    // Case 3: Create a new branch with no children
    ans += solve(v+1, b1, b2, m);
    ans %= MOD;

    // Case 4: Extend existing branch
    ans += solve(v+1, b1, b2, m+1);
    ans %= MOD;

    dp[v][b1][b2][m] = ans;
    return ans;
}

int main() {
    std::cin >> n >> k;

    // Initialize dp array with -1
    std::memset(dp, -1, sizeof(dp));

    int ans = solve(1, 0, 0, 0);
    std::cout << ans << std::endl;

    return 0;
}