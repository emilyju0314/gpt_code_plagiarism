#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

Point reflection(Point p1, Point p2, Point p) {
    Point x;
    double vx = p2.x - p1.x;
    double vy = p2.y - p1.y;
    double d = sqrt(vx * vx + vy * vy);
    double ux = vx / d;
    double uy = vy / d;
    double wx = p.x - p1.x;
    double wy = p.y - p1.y;
    double dot = wx * ux + wy * uy;
    x.x = p1.x + 2 * dot * ux - p.x;
    x.y = p1.y + 2 * dot * uy - p.y;
    return x;
}

int main() {
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p;
        cin >> p.x >> p.y;
        Point x = reflection(p1, p2, p);
        cout << fixed << setprecision(10) << x.x << " " << x.y << endl;
    }
    return 0;
}