#include <iostream>
#include <vector>

struct Point {
    int x, y, z;
};

struct Polygon {
    std::vector<Point> points;
};

double calculateXYArea(const Polygon& poly) {
    // Implement this function to calculate the area of a polygon in the xy-plane
}

double calculateXZArea(const Polygon& poly) {
    // Implement this function to calculate the area of a polygon in the xz-plane
}

double calculateIntersectionArea(const Polygon& poly1, const Polygon& poly2) {
    // Implement this function to calculate the intersection area of two polygons in 3D space
}

double calculateIntersectionVolume(const Polygon& poly1, const Polygon& poly2) {
    // Implement this function to calculate the volume of the intersection of two prisms
}

int main() {
    int m, n;
    
    while (true) {
        std::cin >> m >> n;
        
        if (m == 0 && n == 0) {
            break;
        }
        
        Polygon poly1, poly2;
        
        for (int i = 0; i < m; ++i) {
            Point point;
            std::cin >> point.x >> point.y;
            point.z = 0;
            poly1.points.push_back(point);
        }
        
        for (int i = 0; i < n; ++i) {
            Point point;
            std::cin >> point.x >> point.z;
            point.y = 0;
            poly2.points.push_back(point);
        }
        
        double volume = calculateIntersectionVolume(poly1, poly2);
        std::cout << volume << std::endl;
    }
    
    return 0;
}