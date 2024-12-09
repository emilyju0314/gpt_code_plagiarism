#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

double areaOfPolygon(const std::vector<Point>& points) {
    double area = 0;

    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        area += (points[i].x * points[j].y) - (points[j].x * points[i].y);
    }

    return std::abs(area) / 2.0;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    double area = areaOfPolygon(points);
    std::cout << std::fixed << std::setprecision(1) << area << std::endl;

    return 0;
}