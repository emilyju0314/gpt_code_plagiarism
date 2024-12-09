#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-7;
const double PI = acos(-1.0);

struct Tank {
    int x, y;
    double a, w;
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    vector<Tank> tanks(n);
    for (int i = 0; i < n; i++) {
        cin >> tanks[i].x >> tanks[i].y >> tanks[i].a >> tanks[i].w;
    }

    int k;
    cin >> k;

    double l = 0.0, r = dist(x1, y1, x2, y2), ans = r;
    while (r - l > EPS) {
        double mid = (l + r) / 2.0;
        
        bool dodged = true;
        for (int i = 0; i < n; i++) {
            double dist_to_tank = dist(x1, y1, tanks[i].x, tanks[i].y);
            double time_to_rotate = (fabs(atan2(y1 - tanks[i].y, x1 - tanks[i].x) - tanks[i].a) / tanks[i].w);

            if (time_to_rotate > mid / dist_to_tank) {
                dodged = false;
                break;
            }
        }

        if (dodged) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << setprecision(4) << fixed << ans << endl;

    return 0;
}