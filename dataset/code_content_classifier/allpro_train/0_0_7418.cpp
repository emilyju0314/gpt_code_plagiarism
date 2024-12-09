#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    vector<int> pins(n, -1); // -1 represents no pin, otherwise pin at vertex index
    pins[0] = 0;
    pins[1] = 1;

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int f, t;
            cin >> f >> t;
            f--;
            t--;

            pins[f] = -1;
            pins[t] = t;
        } else if (query == 2) {
            int v;
            cin >> v;
            v--;

            Point p0 = polygon[pins[0]];
            Point p1 = polygon[pins[1]];
            Point pv = polygon[v];

            double angle = atan2(pv.y - p0.y, pv.x - p0.x) - atan2(p1.y - p0.y, p1.x - p0.x);
            double new_x = p1.x + (pv.x - p0.x) * cos(angle) - (pv.y - p0.y) * sin(angle);
            double new_y = p1.y + (pv.x - p0.x) * sin(angle) + (pv.y - p0.y) * cos(angle);

            cout << fixed << setprecision(10) << new_x << " " << new_y << endl;
        }
    }

    return 0;
}