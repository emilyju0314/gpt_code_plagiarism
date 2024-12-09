#include <iostream>
#include <algorithm>

int main() {
    int a, h, w;
    std::cin >> a >> h >> w;

    if (h < a || w < a) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int min_x = a;
    for (int i = 1; i <= a; ++i) {
        int c1 = (h + i) / (a + i);
        int c2 = (w + i) / (a + i);
        if (c1 * c2 >= 1) {
            double x = static_cast<double>((h + i) % (a + i)) / (c1 - 1);
            x = std::max(x, static_cast<double>((w + i) % (a + i)) / (c2 - 1));
            min_x = std::min(min_x, x);
        }
    }

    std::cout << min_x - 1e-9 << std::endl;

    return 0;
}