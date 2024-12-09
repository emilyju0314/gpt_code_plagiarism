#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool isConvexPolygon(Point points[], int n) {
    bool areAllPositive = true;
    bool areAllNegative = true;

    for (int i = 0; i < n; i++) {
        int res = crossProduct(points[i], points[(i+1)%n], points[(i+2)%n]);
        if (res < 0) {
            areAllPositive = false;
        } else if (res > 0) {
            areAllNegative = false;
        }
    }

    return areAllPositive || areAllNegative;
}

int main() {
    int n;
    cin >> n;

    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    if (isConvexPolygon(points, n)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}