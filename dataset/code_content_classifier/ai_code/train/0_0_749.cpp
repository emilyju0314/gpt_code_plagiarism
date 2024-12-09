#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    int x, y;
};

bool compX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compY(const Point& a, const Point& b) {
    return a.y < b.y;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end(), compX);
    
    set<Point, decltype(&compY)> superset(&compY);
    for (int i = 0; i < n; i++) {
        superset.insert(points[i]);
    }

    sort(points.begin(), points.end(), compY);

    for (int i = 0; i < n; i++) {
        superset.insert(points[i]);
    }

    cout << superset.size() << endl;
    for (const auto& p : superset) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}