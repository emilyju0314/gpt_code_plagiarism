#include <iostream>

const int MOD = 1e9 + 7;

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return (n * factorial(n-1)) % MOD;
}

int main() {
    int n;
    std::cin >> n;

    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}