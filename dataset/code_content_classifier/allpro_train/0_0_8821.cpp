#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double min_width(std::vector<Point>& polygon1, std::vector<Point>& polygon2, double L) {
    double min_width = 1e9; // Initialize with a large value

    for (const Point& p1 : polygon1) {
        for (const Point& p2 : polygon2) {
            double dist = distance(p1, p2);
            min_width = std::min(min_width, dist - L);
        }
    }

    return min_width;
}

int main() {
    double L;
    while (std::cin >> L && L > 0) {
        int n1, n2;
        std::cin >> n1;

        std::vector<Point> polygon1(n1);
        for (int i = 0; i < n1; i++) {
            std::cin >> polygon1[i].x >> polygon1[i].y;
        }

        std::cin >> n2;
        std::vector<Point> polygon2(n2);
        for (int i = 0; i < n2; i++) {
            std::cin >> polygon2[i].x >> polygon2[i].y;
        }

        double result = min_width(polygon1, polygon2, L);
        std::cout << result << std::endl;
    }

    return 0;
}