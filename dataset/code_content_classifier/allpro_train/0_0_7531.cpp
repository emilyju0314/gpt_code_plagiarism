#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double cross_product(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double area(const std::vector<Point>& polygon) {
    double result = 0.0;
    for (int i = 0; i < polygon.size(); ++i) {
        result += polygon[i].x * polygon[(i + 1) % polygon.size()].y;
        result -= polygon[i].y * polygon[(i + 1) % polygon.size()].x;
    }
    return std::abs(result) / 2.0;
}

int main() {
    int n, q;
    std::cin >> n;
    std::vector<Point> polygon(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }

    std::cin >> q;
    
    while (q--) {
        Point p1, p2;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
        
        std::vector<Point> cut_polygon;
        for (int i = 0; i < n; ++i) {
            if (cross_product(p1, p2, polygon[i]) >= 0) {
                cut_polygon.push_back(polygon[i]);
            }
            
            if (cross_product(p1, p2, polygon[i]) * cross_product(p1, p2, polygon[(i + 1) % n]) < 0) {
                double t = cross_product(polygon[i], polygon[(i + 1) % n], p1) / cross_product(polygon[i], polygon[(i + 1) % n], p1, p2);
                double new_x = polygon[i].x + t * (polygon[(i + 1) % n].x - polygon[i].x);
                double new_y = polygon[i].y + t * (polygon[(i + 1) % n].y - polygon[i].y);
                cut_polygon.push_back({new_x, new_y});
            }
        }

        std::cout << std::fixed;
        std::cout.precision(8);
        std::cout << area(cut_polygon) << std::endl;
    }

    return 0;
}