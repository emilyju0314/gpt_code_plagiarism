#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> weights(n);
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
        totalWeight += weights[i];
    }

    if (n == 1) {
        if (totalWeight > k)
            std::cout << -1 << std::endl << 0 << std::endl;
        else
            std::cout << 1 << std::endl << 1 << std::endl;
        return 0;
    }

    if (totalWeight % 50 != 0 || totalWeight > n*k) {
        std::cout << -1 << std::endl << 0 << std::endl;
        return 0;
    }

    int halfWeight = 0;
    int dp[52][5012] = {0};
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        halfWeight += weights[i-1] / 2;
        for (int w = 0; w <= halfWeight && w <= k; w++) {
            for (int l = 0; l <= std::min(i, n-i); l++) {
                dp[i][w] += dp[i-1][w-l*50];
                dp[i][w] %= MOD;
            }
        }
    }

    int minRides = n;
    for (int w = 0; w <= halfWeight; w++) {
        for (int l = 0; l <= std::min(n, n-2); l++) {
            if (dp[n-1][w] && totalWeight / 2 - w <= k) {
                minRides = std::min(minRides, n - l);
            }
        }
    }

    if (minRides == n) {
        std::cout << -1 << std::endl << 0 << std::endl;
    } else {
        int ways = 0;
        for (int l = 0; l <= std::min(minRides, n-minRides); l++) {
            ways += dp[n-1][totalWeight/2-l*50];
            ways %= MOD;
        }
        std::cout << minRides << std::endl << ways << std::endl;
    }

    return 0;
}