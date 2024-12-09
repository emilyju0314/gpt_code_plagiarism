#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Point> crystals(n);
    for (int i = 0; i < n; i++) {
        cin >> crystals[i].x >> crystals[i].y;
    }

    set<pair<double, double>> possible_centers;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int missing_count = 0;
            double cx = (crystals[i].x + crystals[j].x) / 2.0;
            double cy = (crystals[i].y + crystals[j].y) / 2.0;

            for (int m = 0; m < n; m++) {
                if (abs(crystals[m].x - cx) != abs(crystals[m].x - crystals[i].x) ||
                    abs(crystals[m].y - cy) != abs(crystals[m].y - crystals[i].y)) {
                    missing_count++;
                }
            }

            if (missing_count <= k) {
                possible_centers.insert({cx, cy});
            }
        }
    }

    if (possible_centers.empty()) {
        cout << -1 << endl;
    } else {
        cout << possible_centers.size() << endl;
        for (auto center : possible_centers) {
            cout << fixed << setprecision(10) << center.first << " " << center.second << endl;
        }
    }

    return 0;
}