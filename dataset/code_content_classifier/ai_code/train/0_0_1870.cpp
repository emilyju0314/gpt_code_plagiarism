#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int R, r, k;
        std::cin >> R >> r >> k;

        double Rn = r;
        if(k > 1) {
            double sinAngle = (R - r) / (R + r);
            Rn = r * sinAngle / (sin(acos(sinAngle) / pow(2, k-1)));
        }

        std::cout << std::fixed << std::setprecision(10) << Rn << "\n";
    }

    return 0;
}