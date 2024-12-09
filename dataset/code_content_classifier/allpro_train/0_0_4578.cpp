#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<pair<int, int>> points;
    int x, y;
    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    pair<int, int> centroid = {0, 0};
    for (auto p : points) {
        centroid.first += p.first;
        centroid.second += p.second;
    }

    double area = 0.5 * abs((points[0].first - points[2].first) * (points[1].second - points[2].second) - (points[1].first - points[2].first) * (points[0].second - points[2].second));

    cout << "Output" << endl << area;

    return 0;
}