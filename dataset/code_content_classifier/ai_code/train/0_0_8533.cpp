#include <iostream>
#include <cstdint>

#define MOD 1000000007

int64_t linear_function(int64_t A, int64_t B, int64_t x) {
    return ((A % MOD) * (x % MOD) + (B % MOD)) % MOD;
}

int64_t g(int64_t A, int64_t B, int64_t n, int64_t x) {
    if (n == 0) {
        return x;
    } else {
        return linear_function(A, B, g(A, B, n - 1, x));
    }
}

int main() {
    int64_t A, B, n, x;
    std::cin >> A >> B >> n >> x;

    int64_t result = g(A, B, n, x);
    std::cout << result << std::endl;

    return 0;
}