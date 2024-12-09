#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

bool compare(Point& p1, Point& p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock- or counterclock-wise
}

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double convexHullPerimeter(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) return 0;

    std::vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[l].y || (points[i].y == points[l].y && points[i].x < points[l].x)) {
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

    double perimeter = 0;
    for (int i = 0; i < hull.size() - 1; i++) {
        perimeter += dist(hull[i], hull[i + 1]);
    }
    perimeter += dist(hull[hull.size() - 1], hull[0]);

    return perimeter;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    double originalPerimeter = convexHullPerimeter(points);

    double minPerimeter = originalPerimeter;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::vector<Point> tempPoints;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    tempPoints.push_back(points[k]);
                }
            }
            double tempPerimeter = convexHullPerimeter(tempPoints);
            minPerimeter = std::min(minPerimeter, tempPerimeter);
        }
    }

    std::cout << std::fixed;
    std::cout.precision(8);
    std::cout << originalPerimeter - minPerimeter << std::endl;

    return 0;
}