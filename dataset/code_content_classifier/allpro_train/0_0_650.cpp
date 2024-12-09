#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n, w, v, u;
    cin >> n >> w >> v >> u;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double maxTime = 0;
    for (int i = 0; i < n; i++) {
        int x1 = points[i].x, x2 = points[(i + 1) % n].x;
        int y1 = points[i].y, y2 = points[(i + 1) % n].y;

        double dist = distance(points[i], points[(i + 1) % n]) / v;
        double t = (double)(x1) / v;

        if (u * t >= y1 && u * t <= y2) {
            maxTime = max(maxTime, dist / u);
        } else if (u * t >= y2 && u * t <= y1) {
            maxTime = max(maxTime, dist / u);
        } else {
            maxTime = max(maxTime, max(dist / u, (double)(x2 - x1) / v));
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << maxTime << endl;

    return 0;
}