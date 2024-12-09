#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    vector<Point> hull;
    
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int t = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() >= t + 1 && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

double calculateArea(vector<Point>& points, double radius) {
    double area = 0;
    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        double d = dist(points[i], points[j]);
        
        double angle = acos(min(1.0, d / (2*radius)));
        
        double triangleArea = (radius * radius * sin(angle) * cos(angle));
        
        area += d * d * tan(angle) - triangleArea;
    }
    
    return area;
}

int main() {
    int n, l;
    cin >> n >> l;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    double low = 0, high = l;
    const double EPS = 1e-6;
    while (high - low > EPS) {
        double mid = (low + high) / 2;
        if (calculateArea(hull, mid) > l) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << calculateArea(hull, low) << endl;

    return 0;
}