#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    Point pts[3];
    for (int i = 0; i < 3; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    double A = 2*(pts[1].x - pts[0].x);
    double B = 2*(pts[1].y - pts[0].y);
    double C = 2*(pts[2].x - pts[0].x);
    double D = 2*(pts[2].y - pts[0].y);

    double E = pow(pts[1].x, 2) - pow(pts[0].x, 2) + pow(pts[1].y, 2) - pow(pts[0].y, 2);
    double F = pow(pts[2].x, 2) - pow(pts[0].x, 2) + pow(pts[2].y, 2) - pow(pts[0].y, 2);

    double cx = (F - E*D/B) / (C - A*D/B);
    double cy = (E - C*cx) / B;

    Point center = {cx, cy};
    double r = dist(center, pts[0]);

    cout << fixed;
    cout.precision(20);
    cout << cx << " " << cy << " " << r << endl;

    return 0;
}