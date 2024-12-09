#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int distance = std::abs(a - b);
    int totalTiredness = 0;

    for (int i = 1; i <= distance; i++) {
        totalTiredness += i;
    }

    std::cout << totalTiredness << std::endl;

    return 0;
}