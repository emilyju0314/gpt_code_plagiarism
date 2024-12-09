#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int X;
    std::cin >> X;

    int K = 360 / gcd(360, X);

    std::cout << K << std::endl;

    return 0;
}