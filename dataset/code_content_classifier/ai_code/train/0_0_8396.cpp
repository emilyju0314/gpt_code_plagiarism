#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x;
    int y;
};

double calculateManhattanDistance(Point p1, Point p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

double calculateLengthOfErodedCoastline(std::vector<Point> coastline, int R) {
    double totalLength = 0.0;
    int N = coastline.size();
    
    for (int i = 0; i < N; i++) {
        Point currentPoint = coastline[i];
        Point nextPoint = coastline[(i + 1) % N];
        totalLength += calculateManhattanDistance(currentPoint, nextPoint);
    }
    
    totalLength -= 2 * R * N;
    
    if (totalLength < 0) {
        return 0.0;
    }
    
    return totalLength;
}

int main() {
    int N, R;

    while (std::cin >> N >> R && N != 0 && R != 0) {
        std::vector<Point> coastline(N);
        
        for (int i = 0; i < N; i++) {
            std::cin >> coastline[i].x >> coastline[i].y;
        }
        
        double length = calculateLengthOfErodedCoastline(coastline, R);
        
        std::cout << std::fixed << length << std::endl;
    }

    return 0;
}