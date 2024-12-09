#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // collinear
    return (val > 0) ? 1 : 2; // 1 for clockwise, 2 for counterclockwise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;
    
    return false;
}

int countIntersections(vector<Point>& poles) {
    int n = poles.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    Point p1 = poles[i], q1 = poles[j], p2 = poles[k], q2 = poles[l];
                    if (doIntersect(p1, q1, p2, q2)) {
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

    vector<Point> poles(n);
    for (int i = 0; i < n; i++) {
        cin >> poles[i].x >> poles[i].y;
    }

    int intersections = countIntersections(poles);
    cout << intersections << endl;

    return 0;
}