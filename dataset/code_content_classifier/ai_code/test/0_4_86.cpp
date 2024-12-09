#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        long long n, k, x;
        std::cin >> n >> k >> x;

        long long total = 1LL << n;
        long long invalid = 0;

        for(int i = 0; i < n - 1; i++) {
            invalid = (invalid * 2 + x) % MOD;
        }

        long long ans = (total - invalid + MOD) % MOD;
        std::cout << ans << std::endl;
    }

    return 0;
}