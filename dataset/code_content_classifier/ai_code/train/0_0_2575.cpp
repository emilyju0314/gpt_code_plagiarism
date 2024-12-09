#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (sqrt(a) + sqrt(b) < sqrt(c)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}