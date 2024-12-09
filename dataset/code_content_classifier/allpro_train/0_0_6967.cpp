#include <iostream>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    long long ans = 1;
    for (int i = 0; i < 3 * n; ++i) {
        ans = (ans * 3) % MOD;
    }

    for (int i = 0; i < n; ++i) {
        ans = (ans - 6 + MOD) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}