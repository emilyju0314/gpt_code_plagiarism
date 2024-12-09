#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

double euclideanDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int R, N;
    std::cin >> R >> N;
    
    // Reading the coordinates of the vertices of polygon P
    std::vector<Point> polygon;
    for (int i = 0; i < N; i++) {
        double x, y;
        std::cin >> x >> y;
        polygon.push_back(Point(x, y));
    }
    
    // Calculating the length of the fence required to surround the building
    double circumference = 2 * M_PI * R;
    for (int i = 0; i < N; i++) {
        circumference += euclideanDistance(polygon[i], polygon[(i+1) % N]);
    }
    
    std::cout << std::fixed << circumference << std::endl;
    
    return 0;
}