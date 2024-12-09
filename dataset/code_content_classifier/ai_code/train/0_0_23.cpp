#include <iostream>
#include <cmath>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    int min_clones = 0;
    if (x * 100 < n * y) {
        min_clones = std::ceil((double)n * y / 100) - x;
    }

    std::cout << min_clones << std::endl;

    return 0;
}