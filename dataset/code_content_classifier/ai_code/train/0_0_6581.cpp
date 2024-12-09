#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double intersectionArea(double c1x, double c1y, double c1r, double c2x, double c2y, double c2r) {
    double d = distance(c1x, c1y, c2x, c2y);

    if (c1r + c2r <= d) {
        return 0.0;
    } else if (c1r >= d + c2r) {
        return PI * c2r * c2r;
    } else if (c2r >= d + c1r) {
        return PI * c1r * c1r;
    } else {
        double angle1 = 2 * acos((c1r * c1r + d * d - c2r * c2r) / (2 * c1r * d));
        double angle2 = 2 * acos((c2r * c2r + d * d - c1r * c1r) / (2 * c2r * d));

        double area1 = 0.5 * angle1 * c1r * c1r - 0.5 * c1r * c1r * sin(angle1);
        double area2 = 0.5 * angle2 * c2r * c2r - 0.5 * c2r * c2r * sin(angle2);

        return area1 + area2;
    }
}

int main() {
    double c1x, c1y, c1r, c2x, c2y, c2r;
    std::cin >> c1x >> c1y >> c1r;
    std::cin >> c2x >> c2y >> c2r;

    double area = intersectionArea(c1x, c1y, c1r, c2x, c2y, c2r);
    
    std::cout << area << std::endl;

    return 0;
}