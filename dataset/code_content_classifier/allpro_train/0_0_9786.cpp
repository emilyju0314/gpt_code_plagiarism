#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y, z;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
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
        if (points[i].x < points[l].x)
            l = i;
    }

    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != l);

    double area = 0.0;
    for (int i = 0; i < hull.size(); i++) {
        int next = (i + 1) % hull.size();
        area += distance(hull[i], hull[next]);
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << area << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y >> points[i].z;
    }

    convexHull(points);

    return 0;
}