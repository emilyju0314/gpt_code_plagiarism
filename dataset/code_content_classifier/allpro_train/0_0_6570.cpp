#include <iostream>
#include <vector>

bool isMondaySaturdayPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    int i = 5;
    int w = 2;
    
    while (i * i <= num) {
        if (num % i == 0) return false;
        i += w;
        w = 6 - w;
    }
    
    return true;
}

void findMondaySaturdayPrimeFactors(int num) {
    std::vector<int> factors;
    for (int i = 2; i <= num; i++) {
        if (num % i == 0 && isMondaySaturdayPrime(i)) {
            factors.push_back(i);
            while (num % i == 0) num /= i;
        }
    }
    
    std::cout << num << ":";
    for (int factor : factors) {
        std::cout << " " << factor;
    }
    std::cout << std::endl;
}

int main() {
    int num;
    while (std::cin >> num) {
        if (num == 1) break;
        findMondaySaturdayPrimeFactors(num);
    }
    
    return 0;
}