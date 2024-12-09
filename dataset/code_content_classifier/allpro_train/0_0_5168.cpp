#include <iostream>

bool isFiniteFraction(long long p, long long q, long long b) {
    while (true) {
        long long d = p / q;
        p %= q;
        if (p == 0) {
            return true;
        }
        if (b % p == 0) {
            return false;
        }
        if (d == 0) {
            return false;
        }
        q = q - p;
        if (q == 1) {
            return true;
        }
        if (q == b) {
            return false;
        }
        if (p == 0) {
            return true;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        long long p, q, b;
        std::cin >> p >> q >> b;

        if (isFiniteFraction(p, q, b)) {
            std::cout << "Finite\n";
        } else {
            std::cout << "Infinite\n";
        }
    }

    return 0;
}