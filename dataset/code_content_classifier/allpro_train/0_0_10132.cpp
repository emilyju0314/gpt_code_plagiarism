#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;
};

struct Building {
    int N;
    int H;
    std::vector<Point> vertices;
};

double distance(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double distanceToBuilding(Point start, Point end, Building building, double theta) {
    // Calculate intersection points
    std::vector<Point> intersections;
    for (int i = 0; i < building.N; ++i) {
        double x1 = building.vertices[i].x;
        double y1 = building.vertices[i].y;
        double x2 = building.vertices[(i + 1) % building.N].x;
        double y2 = building.vertices[(i + 1) % building.N].y;
        
        // Check if line from start to end intersects with building edge
        double det = (x2 - x1) * (end.y - start.y) - (end.x - start.x) * (y2 - y1);
        if (det == 0) continue; // Lines are parallel
        double t = ((end.x - start.x) * (y1 - start.y) - (end.y - start.y) * (x1 - start.x)) / det;
        double s = ((x2 - x1) * (y1 - start.y) - (y2 - y1) * (x1 - start.x)) / det;
        
        if (t > 0 && t < 1 && s > 0 && s < 1) {
            Point intersection = {start.x + t * (end.x - start.x), start.y + t * (end.y - start.y)};
            intersections.push_back(intersection);
        }
    }

    // Find shortest distance among intersection points
    double minDistance = std::numeric_limits<double>::max();
    for (const Point& intersection : intersections) {
        double dist = distance(start, intersection) + distance(intersection, end);
        if (dist < minDistance) {
            minDistance = dist;
        }
    }

    return minDistance;
}

int main() {
    int N;
    while (std::cin >> N && N) {
        std::vector<Building> buildings(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> buildings[i].N >> buildings[i].H;
            buildings[i].vertices.resize(buildings[i].N);
            for (int j = 0; j < buildings[i].N; ++j) {
                std::cin >> buildings[i].vertices[j].x >> buildings[i].vertices[j].y;
            }
        }

        double theta, phi, Sx, Sy, Tx, Ty;
        std::cin >> theta >> phi >> Sx >> Sy >> Tx >> Ty;

        Point start = {Sx, Sy};
        Point end = {Tx, Ty};

        double minDistance = std::numeric_limits<double>::max();
        for (const Building& building : buildings) {
            minDistance = std::min(minDistance, distanceToBuilding(start, end, building, theta));
        }

        std::cout << std::fixed << std::setprecision(5) << minDistance << std::endl;
    }

    return 0;
}