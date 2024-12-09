#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    std::cin >> n;

    int count = 0;
    while(n > 0) {
        int divisor = 2;
        while(n % divisor != 0 || !isPrime(divisor)) {
            divisor++;
        }
        n -= divisor;
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}