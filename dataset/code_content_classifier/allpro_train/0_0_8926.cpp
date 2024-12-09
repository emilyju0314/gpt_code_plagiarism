#include <iostream>
#include <vector>

const int MOD = 998244353;

int n, m;
std::vector<int> c;

int dp[505][505];

int num_ways(int left, int right) {
    if (left >= right) {
        return 1;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    int ways = 0;

    for (int i = left + 1; i <= right; i++) {
        if (c[left] == c[i]) {
            ways = (ways + (1LL * num_ways(left + 1, i) * num_ways(i, right)) % MOD) % MOD;
        }
    }

    return dp[left][right] = ways;
}

int main() {
    std::cin >> n >> m;

    c.resize(m);
    for (int i = 0; i < m; i++) {
        std::cin >> c[i];
    }

    std::memset(dp, -1, sizeof(dp));

    int ans = num_ways(0, m);

    std::cout << ans << std::endl;

    return 0;
}