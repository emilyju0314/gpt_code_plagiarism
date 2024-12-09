#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int q;
    std::cin >> q;

    while(q--) {
        Point p0, p1, p2, p3;
        std::cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        double dist1 = distance(p0, p2);
        double dist2 = distance(p0, p3);
        double dist3 = distance(p1, p2);
        double dist4 = distance(p1, p3);

        double minDist = std::min(std::min(dist1, dist2), std::min(dist3, dist4));
        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << minDist << std::endl;
    }

    return 0;
}