#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

struct Building {
    std::vector<Point> vertices;
    int height;
};

struct Road {
    Point start, end;
};

double distance(Point p1, Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

double minDistanceInSunshine(const std::vector<Building>& buildings, const std::vector<Road>& roads, double sunDirection, double sunElevation, Point start, Point end) {
    // Calculate the shadow cast by each building on the roads
    
    // Calculate the shortest path for Edward
    
    return 0.0; // Placeholder for the result
}

int main() {
    int N, M;
    
    while (true) {
        std::cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        std::vector<Building> buildings(N);
        for (int i = 0; i < N; ++i) {
            int NV, H;
            Building building;
            std::cin >> NV >> H;
            for (int j = 0; j < NV; ++j) {
                Point vertex;
                std::cin >> vertex.x >> vertex.y;
                building.vertices.push_back(vertex);
            }
            building.height = H;
            buildings[i] = building;
        }
        
        std::vector<Road> roads(M);
        for (int i = 0; i < M; ++i) {
            Road road;
            std::cin >> road.start.x >> road.start.y >> road.end.x >> road.end.y;
            roads[i] = road;
        }
        
        double sunDirection, sunElevation;
        Point start, end;
        std::cin >> sunDirection >> sunElevation >> start.x >> start.y >> end.x >> end.y;
        
        double result = minDistanceInSunshine(buildings, roads, sunDirection, sunElevation, start, end);
        
        std::cout << result << std::endl;
    }

    return 0;
}