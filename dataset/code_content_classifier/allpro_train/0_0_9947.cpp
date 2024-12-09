#include <iostream>
#include <cmath>

struct Point {
    int x, y;
};

double getDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool isInsideTriangle(Point p1, Point p2, Point p3, Point p) {
    double area = 0.5 * (-p2.y * p3.x + p1.y * (-p2.x + p3.x) + p1.x * (p2.y - p3.y) + p2.x * p3.y);
    double s = 1 / (2 * area) * (p1.y * p3.x - p1.x * p3.y + (p3.y - p1.y) * p.x + (p1.x - p3.x) * p.y);
    double t = 1 / (2 * area) * (p1.x * p2.y - p1.y * p2.x + (p1.y - p2.y) * p.x + (p2.x - p1.x) * p.y);
    return s > 0 && t > 0 && 1 - s - t > 0;
}

int main() {
    while (true) {
        Point p1, p2, p3, pc;
        int r;
        
        std::cin >> p1.x >> p1.y;
        if (p1.x == 0 && p1.y == 0) break;
        
        std::cin >> p2.x >> p2.y >> p3.x >> p3.y >> pc.x >> pc.y >> r;
        
        double dist1 = getDistance(p1, pc);
        double dist2 = getDistance(p2, pc);
        double dist3 = getDistance(p3, pc);
        
        if (isInsideTriangle(p1, p2, p3, pc) && dist1 <= r && dist2 <= r && dist3 <= r) {
            std::cout << "a" << std::endl;
        } else if (dist1 <= r && dist2 <= r && dist3 <= r) {
            std::cout << "b" << std::endl;
        } else if (isInsideTriangle(p1, p2, p3, pc) || dist1 <= r || dist2 <= r || dist3 <= r) {
            std::cout << "c" << std::endl;
        } else {
            std::cout << "d" << std::endl;
        }
    }
    
    return 0;
}