#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Point {
    int x, y;
};

bool isInsideQuadrilateral(Point p, Point a, Point b, Point c, Point d) {
    int d1 = (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
    int d2 = (b.x - p.x) * (c.y - p.y) - (c.x - p.x) * (b.y - p.y);
    int d3 = (c.x - p.x) * (d.y - p.y) - (d.x - p.x) * (c.y - p.y);
    int d4 = (d.x - p.x) * (a.y - p.y) - (a.x - p.x) * (d.y - p.y);

    return (d1 < 0 && d2 < 0 && d3 < 0 && d4 < 0) || (d1 > 0 && d2 > 0 && d3 > 0 && d4 > 0);
}

int countQuadrilaterals(Point p, vector<Point>& points) {
    int count = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            for (int k = j + 1; k < points.size(); k++) {
                for (int l = k + 1; l < points.size(); l++) {
                    if (isInsideQuadrilateral(p, points[i], points[j], points[k], points[l])) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += countQuadrilaterals(points[i], points);
    }

    cout << result << endl;

    return 0;
}