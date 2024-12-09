#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n;
    cin >> n;

    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    vector<pair<int, int>> red(n);
    vector<pair<int, int>> blue(n);

    for (int i = 0; i < n; i++) {
        cin >> red[i].first >> red[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> blue[i].first >> blue[i].second;
    }

    double total_distance = 0;
    vector<bool> used_blue(n, false);

    for (int i = 0; i < n; i++) {
        double min_dist = 1e9;
        int min_idx = -1;

        for (int j = 0; j < n; j++) {
            if (!used_blue[j]) {
                double dist = distance(red[i].first, red[i].second, blue[j].first, blue[j].second);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_idx = j;
                }
            }
        }

        if (min_idx == -1) {
            cout << "Impossible" << endl;
            return 0;
        }

        total_distance += min_dist;
        used_blue[min_idx] = true;
    }

    cout << fixed << setprecision(10) << total_distance << endl;

    return 0;
}