#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
};

struct Polygons {
    std::vector<Point> vertices;
};

// Function to calculate the area of a polygon
double getArea(const std::vector<Point>& polygon) {
    double area = 0;
    for (int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();
        area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }
    return std::abs(area) / 2.0;
}

// Function to find the intersection of two polygons
std::vector<Point> findIntersection(const std::vector<Point>& p1, const std::vector<Point>& p2) {
    std::vector<Point> result;
    
    // Find intersection of p1 and p2
    // Implementation required
    
    return result;
}

// Function to calculate the common volume of three intersecting polygons
double calculateVolume(const Polygons& p1, const Polygons& p2, const Polygons& p3) {
    double volume = 0.0;
    
    // Find the intersection of first two polygons
    std::vector<Point> intersection1 = findIntersection(p1.vertices, p2.vertices);
    
    // Find the intersection of intersection1 and third polygon
    std::vector<Point> finalIntersection = findIntersection(intersection1, p3.vertices);
    
    // Calculate volume using the finalIntersection polygon
    volume = getArea(finalIntersection);
    
    return volume;
}

int main() {
    int nx, ny, nz;
    while (true) {
        std::cin >> nx;
        if (nx == 0) break;
        
        Polygons p1, p2, p3;
        
        for (int i = 0; i < nx; i++) {
            Point pt;
            std::cin >> pt.x >> pt.y;
            p1.vertices.push_back(pt);
        }
        
        std::cin >> ny;
        for (int i = 0; i < ny; i++) {
            Point pt;
            std::cin >> pt.x >> pt.y;
            p2.vertices.push_back(pt);
        }
        
        std::cin >> nz;
        for (int i = 0; i < nz; i++) {
            Point pt;
            std::cin >> pt.x >> pt.y;
            p3.vertices.push_back(pt);
        }
        
        // Calculate and output the maximum volume
        double maxVolume = calculateVolume(p1, p2, p3);
        std::cout << std::fixed << maxVolume << std::setprecision(4) << std::endl;
    }
    
    return 0;
}