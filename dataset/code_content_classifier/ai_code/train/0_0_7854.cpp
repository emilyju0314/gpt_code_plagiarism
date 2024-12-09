#include <iostream>
#include <cmath>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int maxX = std::min(b, d);
    int maxY = std::min(b, d);

    std::cout << maxX * maxY << std::endl;

    return 0;
}