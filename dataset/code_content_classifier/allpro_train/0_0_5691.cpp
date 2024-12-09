#include <iostream>

int main() {
    long long X;
    std::cin >> X;

    long long happiness_points = 0;
    
    happiness_points += (X / 500) * 1000;
    X %= 500;

    happiness_points += (X / 5) * 5;

    std::cout << happiness_points << std::endl;

    return 0;
}