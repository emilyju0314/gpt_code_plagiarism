#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    // The probability of Andrew winning is maximum when he chooses the number closest to c
    int a = (m > n/2) ? 1 : n;

    std::cout << a << std::endl;

    return 0;
}