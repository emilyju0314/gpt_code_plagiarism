#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int X2;
    std::cin >> X2;

    for (int X0 = X2 - 1; X0 >= 2; X0--) {
        bool valid = true;
        int X1 = X2;
        for (int turn = 0; turn < 2; turn++) {
            bool primeFound = false;
            for (int p = 2; p < X1; p++) {
                if (isPrime(p) && X1 % p == 0) {
                    primeFound = true;
                    int multiple = X1 + p - X1 % p;
                    X1 = multiple;
                    break;
                }
            }
            if (!primeFound) {
                valid = false;
                break;
            }
        }
        if (valid) {
            std::cout << X0 << std::endl;
            break;
        }
    }

    return 0;
}