#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int total_coins = 0;
    int days = 0;

    while (total_coins < C) {
        days++;
        if (days % 7 == 0) {
            total_coins += A + B;
        } else {
            total_coins += A;
        }
    }

    std::cout << days << std::endl;

    return 0;
}