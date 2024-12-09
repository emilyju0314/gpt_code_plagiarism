#include <iostream>
#include <vector>

bool is_prime(int num) {
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
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (is_prime(i)) {
                primes.push_back(i);
            }
        }
        
        int max_twin_prime_size = 0;
        int twin_prime_1 = 0;
        int twin_prime_2 = 0;
        
        for (int i = 0; i < primes.size() - 1; i++) {
            if (primes[i+1] - primes[i] == 2) {
                if (primes[i+1] - primes[i] > max_twin_prime_size) {
                    max_twin_prime_size = primes[i+1] - primes[i];
                    twin_prime_1 = primes[i];
                    twin_prime_2 = primes[i+1];
                }
            }
        }
        
        std::cout << twin_prime_1 << " " << twin_prime_2 << std::endl;
    }
    
    return 0;
}