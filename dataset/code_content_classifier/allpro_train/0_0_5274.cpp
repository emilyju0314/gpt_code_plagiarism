#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
};

bool isCollinear(Point p, Point q, Point r) {
    return fabs((p.x - r.x) * (q.y - r.y) - (p.y - r.y) * (q.x - r.x)) < EPS;
}

bool onSegment(Point p, Point q, Point r) {
    return r.x >= min(p.x, q.x) && r.x <= max(p.x, q.x) &&
           r.y >= min(p.y, q.y) && r.y <= max(p.y, q.y);
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = ((q1.y - p1.y) * (p2.x - p1.x)) - ((q1.x - p1.x) * (p2.y - p1.y);
    int o2 = ((q1.y - p1.y) * (q2.x - p1.x)) - ((q1.x - p1.x) * (q2.y - p1.y);
    int o3 = ((q2.y - p2.y) * (p1.x - p2.x)) - ((q2.x - p2.x) * (p1.y - p2.y);
    int o4 = ((q2.y - p2.y) * (q1.x - p2.x)) - ((q2.x - p2.x) * (q1.y - p2.y);

    if ((o1 * o2 < 0) && (o3 * o4 < 0)) {
        return true;
    }

    if (o1 == 0 && onSegment(p1, q1, p2)) return true;
    if (o2 == 0 && onSegment(p1, q1, q2)) return true;
    if (o3 == 0 && onSegment(p2, q2, p1)) return true;
    if (o4 == 0 && onSegment(p2, q2, q1)) return true;

    return false;
}

int countRegions(vector<Point>& segments) {
    int numRegions = 1;
    int n = segments.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (doIntersect(segments[i], segments[i + 1], segments[j], segments[j + 1])) {
                numRegions++;
            }
        }
    }

    return numRegions;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<Point> segments;

        for (int i = 0; i < n; i++) {
            Point p1, p2;
            cin >> p1.x >> p1.y >> p2.x >> p2.y;
            segments.push_back(p1);
            segments.push_back(p2);
        }

        n *= 2; // Each line requires 2 points

        cout << countRegions(segments) << endl;
    }

    return 0;
}