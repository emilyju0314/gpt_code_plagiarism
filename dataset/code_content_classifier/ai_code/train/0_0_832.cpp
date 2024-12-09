#include <iostream>

bool isPossible(int a, int b) {
    if (a == b) {
        if (a == 1) {
            return true;
        } else {
            return false;
        }
    }

    int gcd = std::__gcd(a, b);
    int product = a * b;
    
    return product == gcd * gcd;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;

        if (isPossible(a, b)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}