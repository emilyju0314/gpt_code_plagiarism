#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    double max_beauty = 0;
    for (int x = 0; x <= w; x++) {
        for (int y = 0; y <= h; y++) {
            vector<double> distances;
            for (auto& point : points) {
                double dist = sqrt((x - point.first) * (x - point.first) + (y - point.second) * (y - point.second));
                distances.push_back(dist);
            }
            sort(distances.begin(), distances.end());
            double beauty = distances[1];
            max_beauty = max(max_beauty, beauty);
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << max_beauty << endl;

    return 0;
}