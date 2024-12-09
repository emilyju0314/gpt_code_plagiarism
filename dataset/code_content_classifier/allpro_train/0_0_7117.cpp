#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

struct Car {
    double x, y, dx, dy, s;
};

bool check_collision(const Car& c1, const Car& c2, double t) {
    double new_x1 = c1.x + c1.dx * t * c1.s;
    double new_y1 = c1.y + c1.dy * t * c1.s;
    double new_x2 = c2.x + c2.dx * t * c2.s;
    double new_y2 = c2.y + c2.dy * t * c2.s;

    return abs(new_x1 - new_x2) <= EPS && abs(new_y1 - new_y2) <= EPS;
}

int main() {
    int n;
    cin >> n;
    
    vector<Car> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i].x >> cars[i].y >> cars[i].dx >> cars[i].dy >> cars[i].s;
    }

    double low = 0.0, high = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double l = 0.0, r = 1e9;
            for (int iter = 0; iter < 100; iter++) {
                double mid = (l + r) / 2.0;
                if (check_collision(cars[i], cars[j], mid)) {
                    high = min(high, mid);
                    break;
                } else {
                    if ((cars[i].dx - cars[j].dx) * (cars[i].dx - cars[j].dx)
                        + (cars[i].dy - cars[j].dy) * (cars[i].dy - cars[j].dy)
                        - (cars[i].s + cars[j].s) * (cars[i].s + cars[j].s) > 0) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
            }
        }
    }

    if (high == 1e9) {
        cout << "No show :(" << endl;
    } else {
        cout << fixed << high << endl;
    }

    return 0;
}