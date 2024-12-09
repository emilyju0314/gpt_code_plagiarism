#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double diameter(std::vector<Point>& points) {
    double maxDist = 0.0;
    int n = points.size();
    int idx1 = 0, idx2 = 0;
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        while (distance(points[i], points[j]) >= distance(points[i], points[(j + 1) % n])) {
            j = (j + 1) % n;
        }
        double dist1 = distance(points[i], points[j]);
        double dist2 = distance(points[(i + n/2) % n], points[(j + n/2) % n]);
        if (dist1 > maxDist) {
            maxDist = dist1;
            idx1 = i;
            idx2 = j;
        }
        if (dist2 > maxDist) {
            maxDist = dist2;
            idx1 = (i + n/2) % n;
            idx2 = (j + n/2) % n;
        }
    }
    
    return maxDist;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }
    
    double result = diameter(points);
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << result << std::endl;
    
    return 0;
}