#include <iostream>
#include <vector>

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }
    
    std::vector<int> result;
    int sum = n;
    while(sum > 0) {
        for(int i = primes.size() - 1; i >= 0; i--) {
            if(sum - primes[i] >= 0) {
                result.push_back(primes[i]);
                sum -= primes[i];
                break;
            }
        }
    }
    
    std::cout << result.size() << std::endl;
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}