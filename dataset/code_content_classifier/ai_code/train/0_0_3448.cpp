#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double triangleArea(const Point& a, const Point& b, const Point& c) {
    return 0.5 * std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> vertices(n);
    for (int i = 0; i < n; i++) {
        char comma;
        std::cin >> vertices[i].x >> comma >> vertices[i].y;
    }

    double totalArea = 0.0;
    for (int i = 1; i < n - 1; i++) {
        totalArea += triangleArea(vertices[0], vertices[i], vertices[i+1]);
    }

    std::cout << totalArea << std::endl;

    return 0;
}