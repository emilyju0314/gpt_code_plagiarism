#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

// Function to calculate area of triangle formed by 3 points
double triangleArea(Point p1, Point p2, Point p3) {
    return 0.5 * std::abs((p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)));
}

// Function to check if a point is inside the triangle
bool isInsideTriangle(Point p1, Point p2, Point p3, Point p) {
    double totalArea = triangleArea(p1, p2, p3);
    double area1 = triangleArea(p, p2, p3);
    double area2 = triangleArea(p1, p, p3);
    double area3 = triangleArea(p1, p2, p);

    return std::abs(totalArea - (area1 + area2 + area3)) < 1e-6;
}

int main() {
    Point p1, p2, p3, p;
    
    while (std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p.x >> p.y) {
        if (isInsideTriangle(p1, p2, p3, p)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}