#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool cmp(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

long long dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;
    
    sort(points.begin(), points.end(), cmp);
    
    vector<Point> upper, lower;
    for (int i = 0; i < n; ++i) {
        while (upper.size() >= 2 && orientation(upper[upper.size()-2], upper.back(), points[i]) != 2) {
            upper.pop_back();
        }
        while (lower.size() >= 2 && orientation(lower[lower.size()-2], lower.back(), points[i]) != 2) {
            lower.pop_back();
        }
        upper.push_back(points[i]);
        lower.push_back(points[i]);
    }
    
    for (int i = lower.size() - 2; i > 0; --i) {
        upper.push_back(lower[i]);
    }
    
    return upper;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> hull = convexHull(points);
    
    double ans = 0.0;
    for (int i = 0; i < hull.size(); ++i) {
        ans += sqrt(dist(hull[i], hull[(i+1)%hull.size()]));
    }
    
    cout << ans << endl;
    
    return 0;
}