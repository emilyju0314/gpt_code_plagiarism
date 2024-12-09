#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double dotProduct(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double pointToLineDistance(Point p, Point l1, Point l2) {
    Point v1 = {l2.x - l1.x, l2.y - l1.y};
    Point v2 = {p.x - l1.x, p.y - l1.y};

    double t = dotProduct(v2, v1) / dotProduct(v1, v1);
    
    if(t <= 0) {
        return dist(p, l1);
    }
    if(t >= 1) {
        return dist(p, l2);
    }

    Point closestPoint = {l1.x + v1.x * t, l1.y + v1.y * t};
    return dist(p, closestPoint);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Point> polygon(n);
    for(int i = 0; i < n; i++) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }

    for(int i = 0; i < m; i++) {
        Point l1, l2;
        std::cin >> l1.x >> l1.y >> l2.x >> l2.y;

        double maxLength = 0;
        for(int j = 0; j < n; j++) {
            double d = pointToLineDistance(polygon[j], l1, l2);
            maxLength = std::max(maxLength, d);
        }

        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << maxLength << std::endl;
    }

    return 0;
}