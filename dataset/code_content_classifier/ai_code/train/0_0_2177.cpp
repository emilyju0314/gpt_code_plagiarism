#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, index;
};

int crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool comparePoints(Point p1, Point p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
    }

    sort(points.begin(), points.end(), comparePoints);

    string s;
    cin >> s;

    vector<int> result;
    result.push_back(points[0].index);
    result.push_back(points[1].index);
    
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == 'L') {
            result.push_back(points[i+2].index);
        } else {
            result.insert(result.begin(), points[i+2].index);
        }
    }

    if (crossProduct(points[0], points[1], points[n-1]) == 0) {
        cout << -1 << endl;
    } else {
        result.push_back(points[n-1].index);

        for (int p : result) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}