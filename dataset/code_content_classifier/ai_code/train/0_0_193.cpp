#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int sorted_pixels[3] = {a, b, c};
    std::sort(sorted_pixels, sorted_pixels + 3);

    if (sorted_pixels[2] - sorted_pixels[0] >= 2) {
        std::cout << sorted_pixels[0] * 2 + 1 << std::endl;
    } else {
        std::cout << (a + b + c) / 3 << std::endl;
    }

    return 0;
}