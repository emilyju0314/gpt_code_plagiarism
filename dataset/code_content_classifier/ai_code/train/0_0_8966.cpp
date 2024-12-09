#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double getAngle(Point a, Point b, Point c) {
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ac = dist(a, c);
    return acos((ab * ab + bc * bc - ac * ac) / (2 * ab * bc));
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double r = 0;
    Point barney, lyanna;

    for (int i = 0; i < n; i++) {
        Point a = points[i];
        Point b = points[(i + 1) % n];
        Point c = points[(i + 2) % n];

        double angle = getAngle(a, b, c);
        if (angle > M_PI / 2) {
            double distA = dist(b, c);
            double distB = dist(a, c);
            double distC = dist(a, b);
            double maxDist = max(distA, max(distB, distC));

            if (maxDist > r) {
                r = maxDist;
                barney = b;
                lyanna = c;
            }
        }
    }

    cout << r << endl;
    cout << barney.x << " " << barney.y << endl;
    cout << lyanna.x << " " << lyanna.y << endl;

    return 0;
}