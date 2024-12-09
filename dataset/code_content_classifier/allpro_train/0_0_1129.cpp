#include <iostream>

int main() {
    int h, w, a, b;
    std::cin >> h >> w >> a >> b;

    int rows = h / a;
    int cols = w / b;

    int remaining_area = h * w - rows * cols * a * b;

    std::cout << remaining_area << std::endl;

    return 0;
}