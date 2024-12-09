#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            char comma;
            std::cin >> points[i].x >> comma >> points[i].y;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 2 && crossProduct(points[i], points[i + 1], points[i + 2]) != 0) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}