#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    vector<double> angles;
    for (int i = 0; i < n; i++) {
        vector<double> v;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                v.push_back(atan2(points[j].second - points[i].second, points[j].first - points[i].first) * 180 / M_PI);
            }
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < v.size(); j++) {
            angles.push_back(v[j] + 360);
            angles.push_back(v[j]);
        }
    }

    double result = 360;
    for (int i = 0; i < angles.size(); i++) {
        int j = (i + 1) % angles.size();
        result = min(result, angles[j] - angles[i]);
    }

    printf("%.10f\n", result);

    return 0;
}