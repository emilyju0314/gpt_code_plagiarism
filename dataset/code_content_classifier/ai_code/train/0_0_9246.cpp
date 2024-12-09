#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(vector<pair<int, int>>& points, int D, long long side) {
    long long minX = LLONG_MAX, minY = LLONG_MAX, maxX = LLONG_MIN, maxY = LLONG_MIN;
    for (auto p : points) {
        long long x = p.first, y = p.second;
        minX = min(minX, x - side + 1);
        minY = min(minY, y - side + 1);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }
    long long width = maxX - minX + 1, height = maxY - minY + 1;
    return max(width, height) <= D;
}

int main() {
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points.begin(), points.end());

    long long left = 0, right = 1e9;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (check(points, D, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}