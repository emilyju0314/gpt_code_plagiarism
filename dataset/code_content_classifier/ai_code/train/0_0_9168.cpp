#include <iostream>
#include <vector>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> primes;
    primes.push_back(2);
    int current_num = 3;

    while (primes.size() < 100000) {
        if (is_prime(current_num)) {
            primes.push_back(current_num);
        }
        current_num += 2;
    }

    int k;
    while (std::cin >> k && k != 0) {
        if (!is_prime(k)) {
            int index = 0;
            while (primes[index] < k) {
                index++;
            }
            int gap = primes[index] - primes[index - 1] - 1;
            std::cout << gap << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }
    }

    return 0;
}