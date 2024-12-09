#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

    int count = 0;
    unordered_map<double, int> slopes;

    for (int i = 0; i < n; i++) {
        slopes.clear();
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double slope = atan2(points[j].y - points[i].y, points[j].x - points[i].x);
                slopes[slope]++;
            }
        }

        for (auto it = slopes.begin(); it != slopes.end(); it++) {
            int s = it->second;
            count += s * (s - 1) / 2;
        }
    }

    cout << count / 2 << endl;

    return 0;
}