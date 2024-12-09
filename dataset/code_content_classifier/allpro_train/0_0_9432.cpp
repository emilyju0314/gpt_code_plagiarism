#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

bool isStarShaped(const std::vector<Point>& polygon) {
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int x1 = polygon[i].x;
        int y1 = polygon[i].y;
        int x2 = polygon[(i + 1) % n].x;
        int y2 = polygon[(i + 1) % n].y;
        int x3 = polygon[(i + 2) % n].x;
        int y3 = polygon[(i + 2) % n].y;
        
        // Calculate the cross product of vectors CP and CQ where P and Q are consecutive vertices
        int crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        
        if (crossProduct <= 0) {
            return false; // Not a star-shaped polygon
        }
    }
    return true; // Star-shaped polygon
}

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) break;
        
        std::vector<Point> polygon(n);
        for (int i = 0; i < n; i++) {
            std::cin >> polygon[i].x >> polygon[i].y;
        }
        
        if (isStarShaped(polygon)) {
            std::cout << "1" << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }
    }
    
    return 0;
}