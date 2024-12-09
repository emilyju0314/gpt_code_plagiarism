#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int x, h;

    while (true) {
        std::cin >> x >> h;

        if (x == 0 && h == 0) {
            break;
        }

        double S = x * x + 2 * x * sqrt(x * x / 4 + h * h);
        
        std::cout << std::fixed << std::setprecision(6) << S << std::endl;
    }

    return 0;
}