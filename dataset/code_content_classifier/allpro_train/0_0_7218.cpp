#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (1LL * res * x) % MOD;
        }
        x = (1LL * x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + (1LL * fact[n] * power(k, n - i)) % MOD * power(m - 1, i - 1) % MOD) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}