#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double timeToReachGirl(const std::vector<Point>& pool, int tg, int tw, Point guardPos, Point girlPos) {
    double minTime = distance(guardPos, girlPos) / tg;

    for (int i = 0; i < pool.size(); ++i) {
        Point p1 = pool[i];
        Point p2 = pool[(i + 1) % pool.size];
        
        double edgeDist = distance(p1, p2);

        double timeOnGround = (edgeDist + distance(guardPos, p1)) / tg;
        double timeUnderwater = distance(p1, p2) / tw + distance(p2, girlPos) / tg;

        minTime = std::min(minTime, std::max(timeOnGround, timeUnderwater));
    }

    return minTime;
}

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) break;

        std::vector<Point> pool(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> pool[i].x >> pool[i].y;
        }

        int tg, tw;
        Point guardPos, girlPos;
        std::cin >> tg >> tw >> guardPos.x >> guardPos.y >> girlPos.x >> girlPos.y;

        double result = timeToReachGirl(pool, tg, tw, guardPos, girlPos);
        std::cout << result << std::endl;
    }

    return 0;
}