#include <iostream>
#include <algorithm>

bool isOverlap(double xa1, double ya1, double xa2, double ya2, double xb1, double yb1, double xb2, double yb2) {
    if (xa2 <= xb1 || xb2 <= xa1 || ya2 <= yb1 || yb2 <= ya1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;

    while (std::cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2) {
        if (isOverlap(xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}