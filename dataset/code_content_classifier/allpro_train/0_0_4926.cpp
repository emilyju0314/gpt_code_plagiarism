#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

Point phantom;

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
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

Point reflect(Point p, Point a, Point b) {
    Point c, intersection;
    c.x = b.x - a.x;
    c.y = b.y - a.y;

    double dot1 = (p.x - a.x) * c.x + (p.y - a.y) * c.y;
    double dot2 = c.x * c.x + c.y * c.y;

    double t = dot1 / dot2;
    
    intersection.x = a.x + t * c.x;
    intersection.y = a.y + t * c.y;

    return {2 * intersection.x - p.x, 2 * intersection.y - p.y};
}

int countImages(Point p, Point u, Point v) {
    Point reflected = reflect(p, u, v);
    int count = 1;

    if (doIntersect(u, v, p, reflected)) {
        return 1;
    }

    while (!doIntersect(u, v, p, reflected)) {
        count++;
        p = reflected;
        reflected = reflect(p, u, v);
        if (count >= 100) return -1;
    }

    return count;
}

int main() {
    while (true) {
        cin >> phantom.x >> phantom.y;
        if (phantom.x == 0 && phantom.y == 0) break;

        Point u1, u2, v1, v2;
        cin >> u1.x >> u1.y >> v1.x >> v1.y;
        cin >> u2.x >> u2.y >> v2.x >> v2.y;

        int totalImages = 0;
        totalImages += countImages(phantom, u1, v1);
        totalImages += countImages(phantom, u2, v2);

        if (totalImages >= 100) {
            cout << "TOO MANY" << endl;
        } else {
            cout << totalImages << endl;
        }
    }

    return 0;
}