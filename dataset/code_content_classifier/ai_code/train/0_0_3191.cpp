#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int enclosed_points(const std::vector<Point>& points) {
    int max_points = 0;
    
    for (int i = 0; i < points.size(); ++i) {
        int count = 1; // Count the current point itself
        for (int j = 0; j < points.size(); ++j) {
            if (i != j && distance(points[i], points[j]) <= 2.0) {
                count++;
            }
        }
        max_points = std::max(max_points, count);
    }
    
    return max_points;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }
        std::cout << enclosed_points(points) << std::endl;
    }
    return 0;
}