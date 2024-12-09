#include <iostream>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

Point getIntersection(Point p0, Point p1, Point p2, Point p3) {
    double A1 = p1.y - p0.y;
    double B1 = p0.x - p1.x;
    double C1 = A1 * p0.x + B1 * p0.y;

    double A2 = p3.y - p2.y;
    double B2 = p2.x - p3.x;
    double C2 = A2 * p2.x + B2 * p2.y;

    double det = A1 * B2 - A2 * B1;

    double x = (B2 * C1 - B1 * C2) / det;
    double y = (A1 * C2 - A2 * C1) / det;

    return {x, y};
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        Point p0, p1, p2, p3;
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        Point intersection = getIntersection(p0, p1, p2, p3);
        cout << fixed << setprecision(10) << intersection.x << " " << intersection.y << endl;
    }

    return 0;
}