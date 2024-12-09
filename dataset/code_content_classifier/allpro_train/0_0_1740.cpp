#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(Point a, Point b) {
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), comparePoints);

    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        int x1 = points[i-1].x;
        int y1 = points[i-1].y;
        int x2 = points[i].x;
        int y2 = points[i].y;
        int x3 = points[i+1].x;
        int y3 = points[i+1].y;

        if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}