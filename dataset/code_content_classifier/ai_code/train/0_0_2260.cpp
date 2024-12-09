#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << n / 2 % 2 << std::endl;
    } else {
        std::cout << (n+1) / 2 % 2 << std::endl;
    }

    return 0;
}