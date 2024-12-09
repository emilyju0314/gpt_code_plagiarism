#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
    double x;
    double y;
};

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Point p1, p2, p3;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        // Midpoint of a line segment
        Point mid1, mid2;
        mid1.x = (p1.x + p2.x) / 2;
        mid1.y = (p1.y + p2.y) / 2;
        mid2.x = (p1.x + p3.x) / 2;
        mid2.y = (p1.y + p3.y) / 2;

        // Slopes of the perpendicular bisectors of the line segments
        double slope1 = -(p2.x - p1.x) / (p2.y - p1.y);
        double slope2 = -(p3.x - p1.x) / (p3.y - p1.y);

        // Calculating the center and radius of the circumscribed circle
        Point center;
        center.x = (mid2.x * slope1 - mid1.x * slope2 - mid2.y + mid1.y) / (slope1 - slope2);
        center.y = slope1 * (center.x - mid1.x) + mid1.y;

        double radius = sqrt((center.x - p1.x) * (center.x - p1.x) + (center.y - p1.y) * (center.y - p1.y));

        // Output the result rounded to three decimal places
        std::cout << std::fixed << std::setprecision(3) << center.x << " " << center.y << " " << radius << std::endl;
    }

    return 0;
}