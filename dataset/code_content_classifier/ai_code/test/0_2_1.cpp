#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool check(const vector<pair<int, int>>& points, int k, double radius) {
    int count = 0;
    for (const auto& p : points) {
        double dist = sqrt(p.first * p.first + p.second * p.second);
        if (dist <= radius) {
            count++;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double low = 0.0, high = 2e5;
    while (high - low > 1e-9) {
        double mid = (low + high) / 2;

        if (check(points, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << high << endl;

    return 0;
}