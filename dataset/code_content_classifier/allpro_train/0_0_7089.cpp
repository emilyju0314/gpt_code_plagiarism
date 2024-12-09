#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    Point p1, p2, p3;

    while (true) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        if (p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0 && p3.x == 0 && p3.y == 0) {
            break;
        }

        double d12 = distance(p1, p2);
        double d23 = distance(p2, p3);
        double d31 = distance(p3, p1);

        double s = (d12 + d23 + d31) / 2;
        double area = sqrt(s * (s - d12) * (s - d23) * (s - d31));

        double r1 = 2 * area / (d23 + d31 + d12);
        double r2 = 2 * area / (d31 + d12 + d23);
        double r3 = 2 * area / (d12 + d23 + d31);

        cout << fixed;
        cout.precision(6);
        cout << r1 << " " << r2 << " " << r3 << endl;
    }

    return 0;
}