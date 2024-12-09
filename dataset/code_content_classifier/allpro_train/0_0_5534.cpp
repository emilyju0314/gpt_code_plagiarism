#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double perimeter(int n, int k, vector<pair<int, int>>& points) {
    sort(points.begin(), points.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second < p2.second;
    });

    double min_perimeter = 1e9;

    for (int i = 0; i <= k; ++i) {
        vector<pair<int, int>> fence_points;
        for (int j = 0; j < i; ++j) {
            fence_points.push_back(points[j]);
        }
        for (int j = k+2; j < n; ++j) {
            fence_points.push_back(points[j]);
        }
        for (int j = 0; j < k + 2; ++j) {
            double total_distance = 0;
            for (int l = 0; l < k + 2; ++l) {
                total_distance += distance(fence_points[j], fence_points[l]);
            }
            min_perimeter = min(min_perimeter, total_distance);
        }
    }

    return min_perimeter;
}

int main() {
    int n, k;
    
    while (cin >> n && n != 0) {
        cin >> k;
        vector<pair<int, int>> points(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        double result = perimeter(n, k, points);
        cout << fixed;
        cout.precision(9);
        cout << result << endl;
    }

    return 0;
}