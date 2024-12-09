#include <iostream>
#include <cmath>

long long factorial(long long n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        if (n % 2 == 1) {
            std::cout << 0 << std::endl;
        } else {
            long long result = factorial(n/2-1) * factorial(n/2-1) * factorial(8);
            std::cout << result << std::endl;
        }
    }
    return 0;
}