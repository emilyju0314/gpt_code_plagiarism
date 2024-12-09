#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, V, m;
    cin >> n >> V;

    vector<double> angles(n);
    for (int i = 0; i < n; i++) {
        cin >> angles[i];
    }

    cin >> m;
    vector<pair<double, double>> walls(m);
    for (int i = 0; i < m; i++) {
        double xi, yi;
        cin >> xi >> yi;
        walls[i] = make_pair(xi, yi);
    }

    double g = 9.8;

    for (int i = 0; i < n; i++) {
        double alpha = angles[i];
        double x_landing = 0.0, y_landing = 0.0;
        
        double t = V * sin(alpha) / g;
        double x_intersection = V * cos(alpha) * t;

        bool hit_wall = false;
        for (auto wall : walls) {
            if (x_intersection >= wall.first) {
                hit_wall = true;
                x_landing = wall.first;
                y_landing = min(V * sin(alpha) * t - 0.5 * g * t * t, wall.second);
                break;
            }
        }

        if (!hit_wall) {
            x_landing = x_intersection;
            y_landing = 0.0;
        }

        cout << fixed;
        cout.precision(10);
        cout << x_landing << " " << y_landing << endl;
    }

    return 0;
}