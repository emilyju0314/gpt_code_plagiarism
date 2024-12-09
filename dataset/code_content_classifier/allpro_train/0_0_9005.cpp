#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the sides of the triangle
    double side_a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double side_b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double side_c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    // Calculate the half perimeter of the triangle
    double s = (side_a + side_b + side_c) / 2;

    // Calculate the inradius and coordinates of the incenter
    double inradius = sqrt((s - side_a) * (s - side_b) * (s - side_c) / s);
    double cx = (side_a * x1 + side_b * x2 + side_c * x3) / (side_a + side_b + side_c);
    double cy = (side_a * y1 + side_b * y2 + side_c * y3) / (side_a + side_b + side_c);

    std::cout.precision(20);
    std::cout << cx << " " << cy << " " << inradius << std::endl;

    return 0;
}