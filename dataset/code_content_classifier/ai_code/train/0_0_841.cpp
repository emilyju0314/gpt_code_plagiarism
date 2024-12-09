#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

int N, M;
long long dp[5005][5005];

long long solve(int n, int m) {
    if (n == 0) return 1;
    if (dp[n][m] != -1) return dp[n][m];

    long long ans = 0;
    ans = (ans + solve(n-1, m-1)) % MOD;
    ans = (ans + (m-1) * solve(n-1, m-1)) % MOD;
    ans = (ans + (m-2) * solve(n-1, m-2)) % MOD;
    ans = (ans + solve(n-1, m-2)) % MOD;

    return dp[n][m] = ans;
}

int main() {
    std::cin >> N >> M;
    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1);

    long long ans = solve(N, M);
    std::cout << ans << std::endl;

    return 0;
}