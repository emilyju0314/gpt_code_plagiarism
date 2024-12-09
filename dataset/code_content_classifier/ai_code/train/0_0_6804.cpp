#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    double min_distance = 1e9;
    for (int i = 0; i < n; i++) {
        double x_diff = vertices[(i + 1) % n].first - vertices[i].first;
        double y_diff = vertices[(i + 1) % n].second - vertices[i].second;
        double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
        min_distance = min(min_distance, distance);
    }

    double answer = min_distance * (m - 1) / m;
    cout << fixed;
    cout.precision(6);
    cout << answer << endl;

    return 0;
}