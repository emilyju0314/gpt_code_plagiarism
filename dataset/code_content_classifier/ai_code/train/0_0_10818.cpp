#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Robot {
    double x, y, vx, vy, u;
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        double vx, vy, r;
        cin >> vx >> vy >> r;

        vector<Robot> robots(n);
        for (int i = 0; i < n; i++) {
            cin >> robots[i].x >> robots[i].y >> robots[i].u;
            robots[i].vx = robots[i].u * vx;
            robots[i].vy = robots[i].u * vy;
        }

        double firstCrashTime = 1e9;
        bool crash = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = robots[j].x - robots[i].x;
                double dy = robots[j].y - robots[i].y;
                double dvx = robots[j].vx - robots[i].vx;
                double dvy = robots[j].vy - robots[i].vy;

                double a = dvx * dvx + dvy * dvy;
                double b = 2 * (dx * dvx + dy * dvy);
                double c = dx * dx + dy * dy - 4 * r * r;

                if (b * b - 4 * a * c <= 1e-8) {  // Robots will collide at some point
                    double t = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                    if (t > 0 && t < firstCrashTime) {
                        firstCrashTime = t;
                        crash = true;
                    }
                }
            }
        }

        if (crash) {
            cout << fixed << setprecision(6) << firstCrashTime << endl;
        } else {
            cout << "SAFE" << endl;
        }
    }

    return 0;
}