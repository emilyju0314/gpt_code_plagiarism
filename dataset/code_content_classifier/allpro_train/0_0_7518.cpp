#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

bool isInsidePolygon(Point p, const std::vector<Point>& polygon) {
    int count = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if ((polygon[i].y > p.y) != (polygon[j].y > p.y) &&
            p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x) {
            count++;
        }
    }
    return count % 2 == 1;
}

int main() {
    Point start, end;
    std::cin >> start.x >> start.y >> end.x >> end.y;

    int N;
    std::cin >> N;
    std::vector<Point> polygon(N);
    for (int i = 0; i < N; i++) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }

    double shortestDistance = distance(start, end);

    for (int i = 0; i < N; i++) {
        double d1 = distance(start, polygon[i]) + distance(end, polygon[i]);
        double d2 = 0;
        if (i < N - 1) {
            d2 = distance(start, polygon[i + 1]) + distance(end, polygon[i + 1]);
        } else {
            d2 = distance(start, polygon[0]) + distance(end, polygon[0]);
        }

        double dist = distance(polygon[i], polygon[(i + 1) % N]);
        if (!isInsidePolygon(start, polygon) || !isInsidePolygon(end, polygon)) {
            shortestDistance = std::min(shortestDistance, d1);
        } else {
            shortestDistance = std::min(shortestDistance, std::min(d1, std::min(d2, d1 + dist)));
        }
    }

    std::cout << shortestDistance << std::endl;

    return 0;
}