#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int intersectionArea(Point p1, Point q1, Point p2, Point q2) {
    if (!doIntersect(p1, q1, p2, q2)) return 0;

    Point lower = {max(p1.x, p2.x), max(p1.y, p2.y)};
    Point upper = {min(q1.x, q2.x), min(q1.y, q2.y)};

    int width = max(0, upper.x - lower.x);
    int height = max(0, upper.y - lower.y);

    return width * height;
}

int main() {
    int N;
    cin >> N;

    vector<Point> segments(N * N); // Store all endpoints
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments[i * 2] = {x1, y1};
        segments[i * 2 + 1] = {x2, y2};
    }

    int total_area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            total_area += intersectionArea(segments[i * 2], segments[i * 2 + 1], segments[j * 2], segments[j * 2 + 1]);
        }
    }

    cout << total_area << endl;

    return 0;
}