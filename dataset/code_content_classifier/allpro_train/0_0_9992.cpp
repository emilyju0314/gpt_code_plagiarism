#include <iostream>
#include <vector>

const int MOD = 7340033;

int powMod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int invMod(int a) {
    return powMod(a, MOD - 2);
}

int calcComb(int n, int k) {
    if (k > n) {
        return 0;
    }
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res = (1LL * res * (n - i)) % MOD;
    }
    for (int i = 1; i <= k; ++i) {
        res = (1LL * res * invMod(i)) % MOD;
    }
    return res;
}

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> dp(k + 1);
        dp[0] = 1;
        for (int j = 1; j <= k; ++j) {
            for (int l = j - 1; l <= k - j; ++l) {
                dp[j] = (dp[j] + 1LL * dp[j - 1] * calcComb((l + 1) * 2, 2)) % MOD;
            }
        }

        std::cout << dp[k] << std::endl;
    }

    return 0;
}