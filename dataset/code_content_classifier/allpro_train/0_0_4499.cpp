#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

bool isInside(const vector<Point>& polygon, const Point& p) {
    int n = polygon.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y < p.y && polygon[j].y >= p.y) || (polygon[j].y < p.y && polygon[i].y >= p.y)) &&
            (polygon[i].x <= p.x || polygon[j].x <= p.x)) {
            inside ^= (polygon[i].x + (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) * (polygon[j].x - polygon[i].x) < p.x);
        }
    }

    return inside;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Point> polygon(n);
    vector<Point> points(m);

    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    for (int i = 0; i < m; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < m; i++) {
        if (isInside(polygon, points[i])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}