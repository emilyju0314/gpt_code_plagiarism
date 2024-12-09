#include <iostream>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double v;
    int t;
    cin >> v >> t;

    int vx, vy, wx, wy;
    cin >> vx >> vy >> wx >> wy;

    double lo = 0, hi = 1e9;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        double x = x1 + mid*v, y = y1 + mid*v;
        if (mid >= t) {
            x += (mid-t)*wx;
            y += (mid-t)*wy;
        } else {
            x += (mid)*vx;
            y += (mid)*vy;
        }

        if (dist(x, y, x2, y2) <= v*mid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << lo << endl;

    return 0;
}