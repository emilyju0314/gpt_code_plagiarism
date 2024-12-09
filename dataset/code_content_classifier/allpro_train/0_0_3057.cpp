#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    double xp, yp, vp, x, y, v, r;
    cin >> xp >> yp >> vp;
    cin >> x >> y >> v >> r;

    double low = 0, high = 1e9;
    while (high - low > 1e-9) {
        double mid = (low + high) / 2;
        double angle = fmod(mid, 2 * M_PI);
        double time_to_reach_persephone = dist(x, y, xp + cos(angle) * vp * mid, yp + sin(angle) * vp * mid) / v;
        double distance_to_star = dist(x, y, cos(angle) * r, sin(angle) * r);
        if (time_to_reach_persephone < distance_to_star / v) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(9) << low << endl;

    return 0;
}