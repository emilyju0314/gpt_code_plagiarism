#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int y1, y2, yw, xb, yb, r;
    std::cin >> y1 >> y2 >> yw >> xb >> yb >> r;

    double yd = yw - yb;

    double xw = (double)(xd * xb - yb * yw - r * r * xd)
               / (xd * xd + r * r);

    double distance = sqrt((xw - xb) * (xw - xb) + yb * yb);

    if (distance <= r) {
        std::cout << std::fixed << std::setprecision(10) << xw << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}