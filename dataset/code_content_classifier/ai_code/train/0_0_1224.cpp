#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> primes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> primes[i];
    }

    long long result = 1;
    for (int i = 0; i < n; i++) {
        long long val = 1;
        for (int j = 0; j < i; j++) {
            val = (val * primes[j]) % MOD;
        }
        result = (result * val) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}