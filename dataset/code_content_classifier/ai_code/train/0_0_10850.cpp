#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1000000007;

int n, q;
std::vector<int> c, b;
std::vector<std::vector<std::vector<int>>> dp;

int calculateGoodArrays(int idx, int sum, int maxVal) {
    if (idx == n) {
        return (sum >= 0 && sum <= maxVal) ? 1 : 0;
    }

    if (dp[idx][sum][maxVal] != -1) {
        return dp[idx][sum][maxVal];
    }

    int ans = 0;
    for (int i = 0; i <= c[idx]; i++) {
        ans = (ans + calculateGoodArrays(idx + 1, sum + i, std::max(maxVal, i))) % MOD;
    }

    dp[idx][sum][maxVal] = ans;
    return ans;
}

int main() {
    std::cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    b.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }

    std::cin >> q;
    std::vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        std::cin >> queries[i];
    }

    dp.resize(n, std::vector<std::vector<int>>(101, std::vector<int>(101, -1)));

    int totalGoodArrays = calculateGoodArrays(0, 0, 0);

    for (int i = 0; i < q; i++) {
        int result = 0;
        for (int j = queries[i]; j <= 100; j++) {
            result = (result + dp[0][0][j]) % MOD;
        }
        std::cout << result << std::endl;
    }

    return 0;
}