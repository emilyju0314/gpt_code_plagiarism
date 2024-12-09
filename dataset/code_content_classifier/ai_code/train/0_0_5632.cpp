#include <iostream>
#include <vector>

const long long MOD = 998244353;

long long mod_pow(long long base, long long exp) {
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
    int n;
    std::cin >> n;

    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long answer = 1;
    for (long long num : numbers) {
        long long num_divisors = 1;
        if (num % 2 == 0) {
            num_divisors = 3;
            if (num % 4 == 0) {
                num_divisors = 4;
            }
        } else {
            num_divisors = 2;
        }
        
        answer = (answer * num_divisors) % MOD;
    }

    std::cout << answer << std::endl;
    std::cout.flush();

    return 0;
}