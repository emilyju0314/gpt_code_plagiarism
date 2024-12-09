#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool checkFeasibility(const vector<pair<int, int>>& points, int k, double r) {
    int count = 0;
    for (const auto& point : points) {
        double distance = sqrt(point.first * point.first + point.second * point.second);
        if (distance <= r) {
            count++;
        }
    }
    return count >= k;
}

double findMinRadius(const vector<pair<int, int>>& points, int k) {
    double left = 0, right = 2e5;
    const double EPS = 1e-6;
    
    while (right - left > EPS) {
        double mid = (left + right) / 2;
        if (checkFeasibility(points, k, mid)) {
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

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double minRadius = findMinRadius(points, k);
    cout << fixed;
    cout.precision(10);
    cout << minRadius << endl;

    return 0;
}