#include <iostream>

int main() {
    int n, d, h;
    std::cin >> n >> d >> h;

    if (d > 2 * h || d < h) {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (int i = 2; i <= h + 1; i++) {
        std::cout << i - 1 << " " << i << std::endl;
    }

    if (d == h) {
        for (int i = h + 2; i <= n; i++) {
            std::cout << 1 << " " << i << std::endl;
        }
    } else {
        std::cout << 1 << " " << h + 2 << std::endl;
        int remaining = d - h;
        int prev = h + 2;
        for (int i = h + 3; i <= h + 2 + remaining; i++) {
            std::cout << prev << " " << i << std::endl;
            prev = i;
        }
        for (int i = h + 3 + remaining; i <= n; i++) {
            std::cout << 2 << " " << i << std::endl;
        }
    }

    return 0;
}