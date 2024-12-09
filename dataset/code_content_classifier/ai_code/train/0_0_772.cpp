#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

bool comparePoints(Point p1, Point p2) {
    if(p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), comparePoints);

    int totalLength = 0;
    for(int i = 0; i < n; i++) {
        totalLength += points[i].x + points[i].y * (n - i - 1);
    }

    cout << totalLength << endl;

    return 0;
}