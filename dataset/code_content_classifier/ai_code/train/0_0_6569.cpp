#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int N;
    while (std::cin >> N) {
        std::vector<Point> vertices(N);
        for (int i = 0; i < N; i++) {
            std::cin >> vertices[i].x >> vertices[i].y;
        }
        
        double total_distance = 0;
        for (int i = 0; i < N; i++) {
            total_distance += distance(vertices[i], vertices[(i+1)%N]);
        }
        
        int thin_tiles = total_distance * 2 / (3 * sqrt(3));
        int thick_tiles = total_distance * 2 / (3 * sqrt(3));
        
        std::cout << thin_tiles << " " << thick_tiles << std::endl;
    }
    
    return 0;
}