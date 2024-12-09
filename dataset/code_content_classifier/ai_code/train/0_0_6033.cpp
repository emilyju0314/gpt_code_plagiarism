#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

bool isInside(Point a, Point b, Point c) {
    return (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) &&
            b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
}

bool intersect(Point a1, Point b1, Point a2, Point b2) {
    if (isInside(a1, b2, a2) || isInside(a1, b2, b2) ||
        isInside(b1, a2, a2) || isInside(b1, a2, b2)) {
        return true;
    }
    return false;
}

int main() {
    Point a1, b1, c1, d1;
    Point a2, b2, c2, d2;

    cin >> a1.x >> a1.y >> b1.x >> b1.y >> c1.x >> c1.y >> d1.x >> d1.y;
    cin >> a2.x >> a2.y >> b2.x >> b2.y >> c2.x >> c2.y >> d2.x >> d2.y;

    if (intersect(a1, c1, a2, c2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}