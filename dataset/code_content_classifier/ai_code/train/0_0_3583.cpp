#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

bool comparePoints(Point a, Point b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int n, k;
    cin >> n >> k;

    if (2 * n < k) {
        cout << "no solution" << endl;
        return 0;
    }

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), comparePoints);

    int d;
    int tot = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ++tot;
            if (points[j].x - points[i].x >= d) 
                break;
            d = min(d, distance(points[i], points[j]));
        }
    }

    if (tot <= k) {
        cout << "no solution" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }

    return 0;
}