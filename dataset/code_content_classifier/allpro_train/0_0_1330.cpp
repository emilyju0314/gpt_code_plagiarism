#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long x;
        std::cin >> x;

        bool found = false;
        for (long long a = 1; a <= cbrt(x); a++) {
            long long b = round(cbrt(x - a * a * a));
            if (a * a * a + b * b * b == x) {
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}