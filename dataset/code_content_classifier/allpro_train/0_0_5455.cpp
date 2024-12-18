#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int isInsidePolygon(std::vector<Point>& polygon, Point t) {
    int n = polygon.size();
    if (n < 3) return 0;
    
    Point extreme = {INT_MAX, t.y};

    int count = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        if (doIntersect(polygon[i], polygon[next], t, extreme)) {
            if (orientation(polygon[i], t, polygon[next]) == 0)
                return 1;

            count++;
        }
    }

    return (count % 2) ? 2 : 0;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        Point t;
        std::cin >> t.x >> t.y;
        std::cout << isInsidePolygon(polygon, t) << std::endl;
    }

    return 0;
}