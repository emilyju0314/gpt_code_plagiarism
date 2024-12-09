#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    int h = 0, v = 0;
    vector<pair<int, int>> horizontal, vertical;

    for (int i = 1; i < n; i++) {
        if (points[i-1].x == points[i].x) {
            v++;
            vertical.push_back({i-1, i});
        } else {
            h++;
            horizontal.push_back({i-1, i});
        }
    }

    cout << h << endl;
    for (auto& wire : horizontal) {
        cout << points[wire.first].x << " " << points[wire.first].y << " "
             << points[wire.second].x << " " << points[wire.second].y << endl;
    }

    cout << v << endl;
    for (auto& wire : vertical) {
        cout << points[wire.first].x << " " << points[wire.first].y << " "
             << points[wire.second].x << " " << points[wire.second].y << endl;
    }

    return 0;
}