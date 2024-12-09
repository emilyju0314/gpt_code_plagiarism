#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool check(const vector<pair<double, double>>& points, int k, double r) {
    int count = 0;
    for (const auto& point : points) {
        double distance = sqrt(point.first * point.first + point.second * point.second);
        if (distance <= r) {
            count++;
        }
    }
    return count >= k;
}

double findMinRadius(const vector<pair<double, double>>& points, int k) {
    double left = 0, right = 2e5;
    const double eps = 1e-6;
    while (right - left > eps) {
        double mid = (left + right) / 2;
        if (check(points, k, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double minRadius = findMinRadius(points, k);
    cout << fixed << minRadius << endl;

    return 0;
}