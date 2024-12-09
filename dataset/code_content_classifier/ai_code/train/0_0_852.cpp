#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> primes;
    for (int i = 5; i <= 10000000; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        int max_quadruplet_size = 13;
        for (int i = n; i >= 13; i--) {
            bool found = false;
            for (int j = 0; j < primes.size() && primes[j] <= i - 6; j++) {
                if (isPrime(primes[j] + 2) && isPrime(primes[j] + 6) && isPrime(primes[j] + 8)) {
                    found = true;
                    max_quadruplet_size = i;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        std::cout << max_quadruplet_size << std::endl;
    }

    return 0;
}