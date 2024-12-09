#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

bool cmp(const Point& p1, const Point& p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) return;

    std::vector<Point> hull;

    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }

    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);

    std::sort(hull.begin(), hull.end(), cmp);

    std::cout << hull.size() << std::endl;
    for (auto& point : hull) {
        std::cout << point.x << " " << point.y << std::endl;
    }
}

int main() {
    int N, M;
    while (true) {
        std::cin >> N >> M;
        if (N == 0 && M == 0) break;

        std::vector<Point> points(M);
        for (int i = 0; i < M; i++) {
            std::cin >> points[i].x >> points[i].y;
        }

        convexHull(points);
    }

    return 0;
}