#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int maxGCD = n / 2;
        std::cout << maxGCD << std::endl;
    }

    return 0;
}