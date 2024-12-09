#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double areaOfIntersection(int n, int r, std::vector<Point> points) {
    double totalArea = 0.0;

    for (int i = 0; i < n; i++) {
        Point p1 = points[i];
        Point p2 = points[(i + 1) % n];
        double d1 = distance(p1, {0, 0});
        double d2 = distance(p2, {0, 0});

        if (d1 <= r && d2 <= r) {
            totalArea += 0.5 * r * r * std::asin(triangleArea(p1, {0, 0}, p2) / r / r) - 0.5 * triangleArea(p1, {0, 0}, p2);
        } else if (d1 <= r || d2 <= r) {
            Point center = {0, 0};
            Point p3 = d1 <= r ? p1 : p2;
            double theta = std::acos((p3.x * p3.x + p3.y * p3.y - r * r) / (2 * distance(p3, center) * r));
            totalArea += 0.5 * r * r * theta - 0.5 * triangleArea(center, p3, {center.x + r, center.y}) + triangleArea(p1, p2, p3);
        } else {
            totalArea += triangleArea(p1, {0, 0}, p2);
        }
    }

    return totalArea;
}

int main() {
    int n, r;
    std::cin >> n >> r;

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    double result = areaOfIntersection(n, r, points);
    std::cout << result << std::endl;

    return 0;
}