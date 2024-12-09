#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int sum = a + b + c;
        int max_songs = std::max({a, b, c});

        if (max_songs == a) {
            if (sum % 2 == 0) {
                std::cout << sum / 2 << std::endl;
            } else {
                std::cout << (sum / 2) + 1 << std::endl;
            }
        } else if (max_songs == b) {
            if (sum % 2 == 0) {
                std::cout << sum / 2 << std::endl;
            } else {
                std::cout << (sum / 2) + 1 << std::endl;
            }
        } else {
            std::cout << sum / 2 << std::endl;
        }
    }

    return 0;
}