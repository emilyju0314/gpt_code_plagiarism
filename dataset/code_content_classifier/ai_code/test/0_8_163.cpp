#include <iostream>
#include <vector>

const int MOD = 1000000007;

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
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        std::cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        int ans = 0;

        int inv_p = power(100 - p, MOD - 2);

        if (rb == rd || cb == cd) {
            ans = 1LL * inv_p * power(2, MOD - 2) % MOD;
        } else {
            ans = 1;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}