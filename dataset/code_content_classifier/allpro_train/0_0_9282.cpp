#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool pointInsideTriangle(Point A, Point B, Point C) {
    int f1 = (B.x - A.x) * (0 - A.y) - (B.y - A.y) * (0 - A.x);
    int f2 = (C.x - B.x) * (0 - B.y) - (C.y - B.y) * (0 - B.x);
    int f3 = (A.x - C.x) * (0 - C.y) - (A.y - C.y) * (0 - C.x);

    return ((f1 >= 0 && f2 >= 0 && f3 >= 0) || (f1 <= 0 && f2 <= 0 && f3 <= 0));
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        Point A = points[i];
        Point B = points[(i + 1) % n];
        Point C = points[(i + 2) % n];

        if (pointInsideTriangle(A, B, C)) {
            cout << "YES" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "NO" << endl;
    }

    return 0;
}