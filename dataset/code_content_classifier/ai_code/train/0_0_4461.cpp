#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double timeToDestination(double x1, double y1, double x2, double y2, double v, double t, double vx, double vy, double wx, double wy) {
    double left = 0, right = 1e9;

    while (right - left > 1e-7) {
        double mid = (left + right) / 2;
        double windX = (mid < t) ? vx : wx;
        double windY = (mid < t) ? vy : wy;

        double dirigibleX = x1 + v * mid + windX * mid;
        double dirigibleY = y1 + v * mid + windY * mid;

        double dist = distance(dirigibleX, dirigibleY, x2, y2);

        if (dist / v > mid) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    double x1, y1, x2, y2, v, t, vx, vy, wx, wy;
    cin >> x1 >> y1 >> x2 >> y2 >> v >> t;
    cin >> vx >> vy >> wx >> wy;

    double time = timeToDestination(x1, y1, x2, y2, v, t, vx, vy, wx, wy);
    cout << time << endl;

    return 0;
}