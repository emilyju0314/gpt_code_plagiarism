#include <iostream>
#include <cmath>

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    std::cin >> n >> k;

    long long total_words = std::pow(k, n);

    long long sum = 0;
    for (int i = 1; i < n; i++) {
        long long count = std::pow(k, i);
        sum += count * count % MOD;
        sum %= MOD;
    }

    long long result = sum * total_words % MOD;
    
    // Calculating the modular inverse of Q mod (10^9 + 7) using Fermat's Little Theorem
    long long qInverse = 1;
    long long power = MOD - 2;
    long long base = total_words;

    while (power > 0) {
        if (power % 2 == 1) {
            qInverse = (qInverse * base) % MOD;
        }
        base = (base * base) % MOD;
        power /= 2;
    }

    result = (result * qInverse) % MOD;

    std::cout << result << "\n";

    return 0;
}