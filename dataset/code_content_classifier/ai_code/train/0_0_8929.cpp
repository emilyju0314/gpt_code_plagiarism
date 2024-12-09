#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, z, id;
};

bool comparePoints(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
        points[i].id = i+1;
    }

    sort(points.begin(), points.end(), comparePoints);

    for (int i = 0; i < n; i += 2) {
        cout << points[i].id << " " << points[i+1].id << endl;
    }

    return 0;
}