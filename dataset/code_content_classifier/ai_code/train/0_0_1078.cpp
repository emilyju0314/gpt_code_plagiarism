#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    std::cin >> k;
    
    std::vector<int> beautiful_set;
    
    for (int i = 2; beautiful_set.size() < k; i++) {
        if (is_prime(i)) {
            beautiful_set.push_back(i);
        }
    }
    
    for (int i = 0; i < k; i++) {
        std::cout << beautiful_set[i] << " ";
    }
    
    return 0;
}