#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    int inv100 = 495017523; // pre-calculated inverse of 100 modulo MOD

    int ans = 0;
    int prob = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans + (1LL * prob * (i + 1) % MOD) * inv100 % MOD) % MOD;
        prob = 1LL * prob * p[i] % MOD * inv100 % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}