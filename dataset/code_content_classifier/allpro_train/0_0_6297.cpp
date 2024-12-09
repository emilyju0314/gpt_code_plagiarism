#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int p) {
    if (p <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> coefficients(N + 1);
    
    for (int i = 0; i <= N; i++) {
        std::cin >> coefficients[i];
    }
    
    std::vector<int> primes;

    for (int p = 2; p <= 1000000; p++) {
        if (is_prime(p)) {
            bool divides = true;
            for (int x = -100; x <= 100; x++) {
                long long value = 0;
                for (int i = 0; i <= N; i++) {
                    value += coefficients[i] * pow(x, i);
                }
                if (value % p != 0) {
                    divides = false;
                    break;
                }
            }
            if (divides) {
                primes.push_back(p);
            }
        }
    }

    for (int prime : primes) {
        std::cout << prime << std::endl;
    }

    return 0;
}