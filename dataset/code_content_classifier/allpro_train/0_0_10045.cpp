#include <iostream>
#define MOD 1000000007

long long power(long long x, long long y) {
    if (y == 0) return 1;
    long long ans = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return ans;
}

int main() {
    long long n, m;
    std::cin >> n >> m;

    long long result = 0;
    if (n == 1) {
        result = m + 1;
    } else {
        result = (((m - n + 2) % MOD) * power(2, n - 1) % MOD - 1) % MOD;
        result = (result + MOD) % MOD;
    }

    std::cout << result << std::endl;
    return 0;
}