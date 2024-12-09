#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<pair<int, int>> columns(n);
        for (int i = 0; i < n; i++) {
            cin >> columns[i].first >> columns[i].second;
        }

        double min_width = 1e9; // Initialize to a large value
        double max_width = 0;
        double theta_min, theta_max;
        double epsilon = 1e-10;

        for (double theta = 0.0; theta <= M_PI; theta += 0.00001) {
            double min_x = 1e9;
            double max_x = -1e9;

            for (auto col : columns) {
                double x = col.first * cos(theta) + col.second * sin(theta);
                min_x = min(min_x, x);
                max_x = max(max_x, x);
            }

            double width = max_x - min_x;
            if (width < min_width) {
                min_width = width;
                theta_min = theta;
            }
            if (width > max_width) {
                max_width = width;
                theta_max = theta;
            }
        }

        cout << theta_min << endl;
        cout << theta_max << endl;
    }

    return 0;
}