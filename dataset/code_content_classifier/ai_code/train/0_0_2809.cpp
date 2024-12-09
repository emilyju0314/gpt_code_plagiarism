#include <iostream>
#include <cmath>

int main() {
    int a, b, s;
    std::cin >> a >> b >> s;

    int steps_needed = abs(a) + abs(b);
    if (s < steps_needed || s % 2 != steps_needed % 2) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}