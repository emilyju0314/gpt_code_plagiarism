#include <iostream>

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, num, count = 0;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::cin >> num;
        if(isPrime(num)) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}