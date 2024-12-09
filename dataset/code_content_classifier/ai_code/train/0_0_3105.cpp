#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int m, n;
    
    while (true) {
        std::cin >> m >> n;
        
        if (m == 0 && n == 0) break;
        
        std::vector<Point> points;
        
        for (int i = 0; i < m + n; i++) {
            Point p;
            std::cin >> p.x >> p.y;
            points.push_back(p);
        }
        
        double totalLength = 0;
        for (int i = 1; i < m; i++) {
            totalLength += calculateDistance(points[i], points[i+1]);
        }
        
        std::cout << totalLength << std::endl;
    }
    
    return 0;
}