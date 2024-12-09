#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, w;
};

bool comparePoints(Point p1, Point p2) {
    return p1.w < p2.w;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].w = points[i].y - points[i].x;
    }
    
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    
    sort(points.begin(), points.end(), comparePoints);
    
    for (int i = 0; i < n; i++) {
        if (points[i].w != order[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
    
    return 0;
}