#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y, z, w, v;
};

bool isGoodPoint(Point a, vector<Point>& points) {
    for (Point& p : points) {
        if (p.x == a.x && p.y == a.y && p.z == a.z && p.w == a.w && p.v == a.v) {
            continue;
        }

        int scalarProduct = a.x * p.x + a.y * p.y + a.z * p.z + a.w * p.w + a.v * p.v;
        int lengthA = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w + a.v * a.v;
        int lengthB = p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w + p.v * p.v;
        
        if (scalarProduct > 0 && scalarProduct * scalarProduct > lengthA * lengthB) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z >> points[i].w >> points[i].v;
    }

    vector<int> goodPoints;
    for (int i = 0; i < n; i++) {
        if (isGoodPoint(points[i], points)) {
            goodPoints.push_back(i+1);
        }
    }

    cout << goodPoints.size() << endl;
    for (int gp : goodPoints) {
        cout << gp << endl;
    }

    return 0;
}