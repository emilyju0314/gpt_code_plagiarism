#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double eps = 1e-6;

struct Light {
    int x, y, a;
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<Light> lights(n);
    for (int i = 0; i < n; i++) {
        cin >> lights[i].x >> lights[i].y >> lights[i].a;
    }

    double maxDist = 0;
    for (double x = l; x <= r; x += 0.1) {
        for (double y = 0; y <= 1000; y += 0.1) {
            double d = 1000000; // initial large value
            for (int i = 0; i < n; i++) {
                double angle = atan2(y - lights[i].y, x - lights[i].x) * 180 / M_PI;
                while (angle < 0) angle += 360;
                double diff = abs(angle - lights[i].a);
                if (diff > 180) diff = 360 - diff;
                if (diff <= lights[i].a) {
                    d = min(d, dist(x, y, lights[i].x, lights[i].y) / cos(diff * M_PI / 180));
                }
            }
            maxDist = max(maxDist, d);
        }
    }

    cout.precision(9);
    cout << fixed << maxDist << endl;

    return 0;
}