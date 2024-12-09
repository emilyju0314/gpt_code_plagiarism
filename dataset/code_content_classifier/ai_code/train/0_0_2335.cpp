#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x;
    int y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

std::vector<Point> findPolygon(const std::vector<Point>& points, const Point& bomb) {
    std::vector<Point> polygon;
    for (int i = 0; i < points.size(); i++) {
        polygon.push_back(points[i]);
        if (i < points.size() - 1) {
            if (points[i].x <= bomb.x && points[i + 1].x >= bomb.x) {
                double ratio = (double)(bomb.x - points[i].x) / (points[i + 1].x - points[i].x);
                int y = points[i].y + ratio * (points[i + 1].y - points[i].y);
                polygon.push_back({bomb.x, y});
            }
            if (points[i].x >= bomb.x && points[i + 1].x <= bomb.x) {
                double ratio = (double)(bomb.x - points[i + 1].x) / (points[i].x - points[i + 1].x);
                int y = points[i + 1].y + ratio * (points[i].y - points[i + 1].y);
                polygon.push_back({bomb.x, y});
            }
        }
    }
    return polygon;
}

double minDistance(const std::vector<Point>& polygon, const Point& bomb) {
    double minDist = distance(polygon[0], {0, 0});
    for (int i = 0; i < polygon.size(); i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % polygon.size()];
        double dist = distance(p1, {0, 0});
        minDist = std::min(minDist, dist);

        double A = p2.x - p1.x;
        double B = p1.y - p2.y;
        double C = -A * p1.x - B * p1.y;
        double d = abs(A * 0 + B * 0 + C) / sqrt(pow(A, 2) + pow(B, 2));
        minDist = std::min(minDist, d);

        double t = (0 - p1.x) * (p2.x - p1.x) + (0 - p1.y) * (p2.y - p1.y);
        t /= pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
        if (t >= 0.0 && t <= 1.0) {
            int x = p1.x + t * (p2.x - p1.x);
            int y = p1.y + t * (p2.y - p1.y);
            double dist = distance({x, y}, {0, 0});
            minDist = std::min(minDist, dist);
        }
    }
    return minDist;
}

int main() {
    int N;
    while (std::cin >> N && N > 0) {
        Point bomb;
        std::cin >> bomb.x >> bomb.y;
        
        double minDist = INFINITY;
        for (int i = 0; i < N; i++) {
            int m;
            std::cin >> m;
            std::vector<Point> polygon;
            for (int j = 0; j < m; j++) {
                Point p;
                std::cin >> p.x >> p.y;
                polygon.push_back(p);
            }

            std::vector<Point> extendedPolygon = findPolygon(polygon, bomb);
            double dist = minDistance(extendedPolygon, bomb);
            minDist = std::min(minDist, dist);
        }

        std::cout << std::fixed;
        std::cout.precision(8);
        std::cout << minDist << std::endl;
    }

    return 0;
}