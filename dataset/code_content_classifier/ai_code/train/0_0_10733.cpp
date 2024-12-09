#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

int calculateDamage(const std::vector<std::vector<Point>>& polygons, const Point& spawnPoint, const Point& facility) {
    int totalDamage = 0;
    
    for (const auto& polygon : polygons) {
        int n = polygon.size();
        bool inside = false;
        
        for (int i = 0, j = n - 1; i < n; j = i++) {
            if ((polygon[i].y > spawnPoint.y) != (polygon[j].y > spawnPoint.y) &&
                spawnPoint.x < (polygon[j].x - polygon[i].x) * (spawnPoint.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x) {
                inside = !inside;
            }
        }
        
        int distance = std::sqrt(std::pow(spawnPoint.x - facility.x, 2) + std::pow(spawnPoint.y - facility.y, 2));
        if (inside) totalDamage += distance;
    }
    
    return totalDamage;
}

int main() {
    int numPolygons;
    std::cin >> numPolygons;
    
    std::vector<std::vector<Point>> polygons(numPolygons);
    
    for (int i = 0; i < numPolygons; ++i) {
        int numVertices;
        std::cin >> numVertices;
        
        polygons[i].resize(numVertices);
        for (int j = 0; j < numVertices; ++j) {
            std::cin >> polygons[i][j].x >> polygons[i][j].y;
        }
    }
    
    int numPairs;
    std::cin >> numPairs;
    
    for (int i = 0; i < numPairs; ++i) {
        Point spawnPoint, facility;
        std::cin >> spawnPoint.x >> spawnPoint.y >> facility.x >> facility.y;
        
        int minDamage = calculateDamage(polygons, spawnPoint, facility);
        std::cout << minDamage << std::endl;
    }
    
    return 0;
}