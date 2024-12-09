#include <iostream>
#include <cmath>

int main() {
    while (true) {
        int a, b, c;
        std::cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        
        int D = b * b - 4 * a * c;
        
        if (D >= 0 && std::sqrt(D) == (int)std::sqrt(D)) {
            int p = -b + std::sqrt(D);
            int q = -b - std::sqrt(D);
            int r = 2 * a;
            int s = 2 * a;

            if (p > r || (p == r && q >= s)) {
                std::cout << p << " " << q << " " << r << " " << s << std::endl;
            } else {
                std::cout << "Impossible" << std::endl;
            }
        } else {
            std::cout << "Impossible" << std::endl;
        }
    }

    return 0;
}