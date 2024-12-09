#include <iostream>

int main() {
    long long H;
    std::cin >> H;

    long long attacks = 0;
    long long health = H;

    while (health > 0) {
        attacks++;
        health /= 2;
    }

    std::cout << attacks << std::endl;

    return 0;
}