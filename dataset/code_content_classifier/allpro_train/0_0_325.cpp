#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

int findMinRicePoints(const std::vector<Point>& polygon) {
    int n = polygon.size();
    if (n <= 3) return n;
    
    int count = 0;
    Point p = polygon[0];
    for (int i = 1; i < n; ++i) {
        Point q = polygon[i];
        Point r = polygon[(i + 1) % n];
        
        if (orientation(p, q, r) != 1) {
            count++;
            p = q;
        }
    }
    
    return count;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Point> polygon(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> polygon[i].x >> polygon[i].y;
        }
        
        std::cout << findMinRicePoints(polygon) << std::endl;
    }
    
    return 0;
}