#include <iostream>

bool isPrime(int num) {
    if (num < 2) {
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
    std::cin >> n;

    for (int m = 1; m <= 1000; m++) {
        if (!isPrime(n * m + 1)) {
            std::cout << m << std::endl;
            break;
        }
    }

    return 0;
}