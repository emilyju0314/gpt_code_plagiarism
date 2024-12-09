#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, p, q;
        std::cin >> a >> b >> p >> q;

        double max_val = 0.0;
        int min_x = a;
        for (int x = a; x <= b; x++) {
            double val = abs(sin(M_PI * p / q * x));
            if (val > max_val) {
                max_val = val;
                min_x = x;
            }
        }

        std::cout << min_x << std::endl;
    }

    return 0;
}