#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int sum = a + b + c;
        int max_songs = std::max({a, b, c});
        int min_songs = std::min({a, b, c});

        if (max_songs == sum) {
            std::cout << "0" << std::endl;
        } else {
            int diff = sum % 2 == 0 ? 0 : 1;
            std::cout << std::abs(max_songs - min_songs) + diff << std::endl;
        }
    }

    return 0;
}