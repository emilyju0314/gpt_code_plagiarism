#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y, a;
};

bool checkIntersection(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    int v1 = (p4.x - p3.x)*(p1.y - p3.y) - (p4.y - p3.y)*(p1.x - p3.x);
    int v2 = (p4.x - p3.x)*(p2.y - p3.y) - (p4.y - p3.y)*(p2.x - p3.x);
    int v3 = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    int v4 = (p2.x - p1.x)*(p4.y - p1.y) - (p2.y - p1.y)*(p4.x - p1.x);
    return (v1 * v2 < 0) && (v3 * v4 < 0);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].a;
    }

    vector<pair<int, int>> operations;

    for (int i = 0; i < n; i++) {
        while (points[i].a != i+1) {
            int j;
            for (j = i+1; j < n; j++) {
                if (points[j].a == i+1) {
                    break;
                }
            }

            if (checkIntersection(points[i], points[j], points[points[i].a-1], points[points[j].a-1])) {
                cout << -1 << endl;
                return 0;
            }

            operations.push_back({i+1, j+1});
            swap(points[i].a, points[j].a);
        }
    }

    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}