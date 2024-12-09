#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, z, idx;
};

bool cmp_x(Point &a, Point &b) {
    return a.x < b.x;
}

bool cmp_y(Point &a, Point &b) {
    return a.y < b.y;
}

bool cmp_z(Point &a, Point &b) {
    return a.z < b.z;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
        points[i].idx = i + 1;
    }

    sort(points.begin(), points.end(), cmp_x);
    for (int i = 0; i < n; i += 2) {
        cout << points[i].idx << " " << points[i+1].idx << endl;
    }

    return 0;
}