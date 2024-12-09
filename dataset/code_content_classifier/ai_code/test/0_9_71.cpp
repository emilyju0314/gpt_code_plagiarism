#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y, index;
};

bool compareDistance(Point a, Point b) {
    double distanceA = hypot(a.x - startPoint.x, a.y - startPoint.y);
    double distanceB = hypot(b.x - startPoint.x, b.y - startPoint.y);
    return distanceA < distanceB;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
    }

    startPoint = points[K - 1];
    points.erase(points.begin() + K - 1);

    std::sort(points.begin(), points.end(), compareDistance);

    double minPathLength = 0.0;
    for (int i = 0; i < N - 1; i++) {
        minPathLength += hypot(points[i].x - startPoint.x, points[i].y - startPoint.y);
        startPoint = points[i];
    }

    std::cout << minPathLength << std::endl;

    return 0;
}