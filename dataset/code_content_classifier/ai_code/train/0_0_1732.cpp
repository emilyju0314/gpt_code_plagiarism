#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p0, Point p1, Point p2) {
    int val = (p1.y - p0.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p1.x - p0.x);
    if (val == 0) {
        return 0; // Colinear
    }
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

int main() {
    Point p0, p1;
    cin >> p0.x >> p0.y >> p1.x >> p1.y;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        Point p2;
        cin >> p2.x >> p2.y;

        int result = orientation(p0, p1, p2);

        if (result == 0) {
            cout << "ON_SEGMENT" << endl;
        } else if (result == 1) {
            cout << "COUNTER_CLOCKWISE" << endl;
        } else {
            cout << "CLOCKWISE" << endl;
        }
    }

    return 0;
}