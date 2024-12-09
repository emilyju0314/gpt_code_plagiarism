#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    
    while (std::cin >> N) {
        int pairs = 0;
        
        for (int i = 1; i <= N; i++) {
            if (isPrime(i) && isPrime(N - i + 1)) {
                pairs++;
            }
        }
        
        std::cout << pairs << std::endl;
    }
    
    return 0;
}