#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(const Point &a, const Point &b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end(), comparePoints);
    
    for(int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
    
    return 0;
}