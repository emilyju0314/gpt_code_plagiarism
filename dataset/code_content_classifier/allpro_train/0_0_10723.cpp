#include <iostream>

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }
    
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    
    while(std::cin >> n) {
        int smaller = n - 1;
        int larger = n + 1;
        
        while(!isPrime(smaller)) {
            smaller--;
        }
        
        while(!isPrime(larger)) {
            larger++;
        }
        
        std::cout << smaller << " " << larger << std::endl;
    }
    
    return 0;
}