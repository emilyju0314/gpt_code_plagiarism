#include <iostream>
#include <cmath>

bool is_prime(int m, int n) {
    int divisors = 0;
    if (m * m + n * n == 1) return false;

    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (x == 0 && y == 0) continue;
            if (m * m + n * n == 1) {
                if (m * x + n * y == 0 && m * y - n * x == 1) divisors++;
            } else {
                if ((m * m + n * n) % (m * x + n * y) == 0 && (m * m + n * n) % (m * y - n * x) == 0) divisors++;
            }
        }
    }

    return divisors == 8;
}

int main() {
    int datasets;
    std::cin >> datasets;

    while (datasets--) {
        int m, n;
        std::cin >> m >> n;

        if (is_prime(m, n)) {
            std::cout << 'P' << std::endl;
        } else {
            std::cout << 'C' << std::endl;
        }
    }

    return 0;
}