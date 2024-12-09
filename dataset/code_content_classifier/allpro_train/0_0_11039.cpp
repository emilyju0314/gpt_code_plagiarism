#include <iostream>
#include <cmath>

int main() {
    int h, w;
    std::cin >> h >> w;

    int height = std::min(w, std::max(2, int(pow(2, ceil(log2(h * 0.8))))));
    int width = std::min(h, std::max(2, int(pow(2, ceil(log2(w / 1.25)))));

    std::cout << height << " " << width << std::endl;

    return 0;
}