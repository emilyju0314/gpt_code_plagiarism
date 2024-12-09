#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long c = 0;
    long long total_operations = 0;
    long long total_combinations = 1;
    long long same_combinations = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            c++;
        } else {
            if (same_combinations > 1) {
                total_operations = (total_operations + same_combinations) % MOD;
                total_combinations = (total_combinations * same_combinations) % MOD;
                same_combinations--;
            }
            same_combinations++;
        }
    }

    if (c > 0) {
        long long numerator = (total_operations + total_combinations * c) % MOD;
        long long denominator = (total_combinations * power(k, c)) % MOD;
        long long inverse_denominator = power(denominator, MOD - 2);
        
        long long result = (numerator * inverse_denominator) % MOD;
        std::cout << result << std::endl;
    } else {
        std::cout << total_operations << std::endl;
    }

    return 0;
}