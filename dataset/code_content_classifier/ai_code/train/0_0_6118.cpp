#include <iostream>
#include <cmath>

int main() {
    int a, b, l;
    std::cin >> a >> b >> l;

    double max_width = sqrt(l*l - std::min(a, l)*std::min(a, l) - std::min(b, l)*std::min(b, l));
    if (max_width >= 10e-7) {
        std::cout << std::fixed << max_width << std::endl;
    } else {
        std::cout << "My poor head =(" << std::endl;
    }

    return 0;
}