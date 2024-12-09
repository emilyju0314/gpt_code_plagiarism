#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    long long n, k, l, m;
    std::cin >> n >> k >> l >> m;

    long long ans = 1;
    long long power2l = 1LL << l;

    if (l == 0) {
        ans = power(k, n);
    } else {
        std::vector<long long> dp1(power2l, 0);
        std::vector<long long> dp2(power2l, 0);
        dp1[0] = power(k, n);

        for (long long i = 0; i < power2l; ++i) {
            long long cnt = dp1[i];
            dp1[i] = 0;

            long long zero_cnt = 0;
            for (int j = 0; j < l; ++j) {
                zero_cnt += ((i >> j) & 1);
            }

            for (int j = 0; j < l; ++j) {
                dp2[i | (1LL << j)] += cnt;
                dp2[i | (1LL << j)] %= MOD;
            }

            dp2[i] += (cnt * power(k, n - zero_cnt)) % MOD;
            dp2[i] %= MOD;
        }

        for (long long i = 0; i < power2l; ++i) {
            ans += dp2[i];
            ans %= MOD;
        }
    }

    ans = (ans + MOD) % MOD;
    std::cout << ans << std::endl;

    return 0;
}