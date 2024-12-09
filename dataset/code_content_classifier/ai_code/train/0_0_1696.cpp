#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double minCost(Point start, Point end, std::vector<Point> island) {
    double minDist = distance(start, end);

    for (int i = 0; i < island.size(); i++) {
        int j = (i + 1) % island.size();
        double d = distance(start, island[i]) + distance(island[i], island[j]) + distance(island[j], end);
        minDist = std::min(minDist, d);
    }

    return minDist;
}

int main() {
    Point start, end;
    std::cin >> start.x >> start.y >> end.x >> end.y;

    int n;
    std::cin >> n;

    std::vector<Point> island(n);
    for (int i = 0; i < n; i++) {
        std::cin >> island[i].x >> island[i].y;
    }

    double cost = minCost(start, end, island);
    std::cout << cost << std::endl;

    return 0;
}