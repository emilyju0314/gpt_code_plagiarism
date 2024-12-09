#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;
};

Point getCrossPoint(Point p1, Point p2, Point c, double r) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double A = dx*dx + dy*dy;
    double B = 2*(dx*(p1.x - c.x) + dy*(p1.y - c.y));
    double C = (p1.x - c.x)*(p1.x - c.x) + (p1.y - c.y)*(p1.y - c.y) - r*r;

    double D = B*B - 4*A*C;
    double t1 = (-B + sqrt(D)) / (2*A);
    double t2 = (-B - sqrt(D)) / (2*A);

    Point cp1 = {p1.x + t1*dx, p1.y + t1*dy};
    Point cp2 = {p1.x + t2*dx, p1.y + t2*dy};

    if(cp1.x < cp2.x || (cp1.x == cp2.x && cp1.y < cp2.y)) {
        return cp1;
    } else {
        return cp2;
    }
}

int main() {
    double cx, cy, r;
    int q;
    std::cin >> cx >> cy >> r;
    std::cin >> q;

    while(q--) {
        Point p1, p2;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
        Point crossPoint = getCrossPoint(p1, p2, {cx, cy}, r);
        std::cout << std::fixed << std::setprecision(8) << crossPoint.x << " " << crossPoint.y << " " << crossPoint.x << " " << crossPoint.y << "\n";
    }

    return 0;
}