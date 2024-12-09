#include <iostream>

const int MOD = 1e9+7;

int main() {
    int a, b;
    std::cin >> a >> b;

    long long ans = 0;

    for(int k = 1; k <= a; k++) {
        int start = k + b;
        int end = a * b;

        if(start > end) {
            continue;
        }

        long long cnt = end / b - (start - 1) / b;
        ans = (ans + (cnt * (2 * start + (cnt - 1) * b)) % MOD) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}