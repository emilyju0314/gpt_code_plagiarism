#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define EPS 1e-9

struct Point {
    double x, y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    
    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
    
    double norm() const {
        return sqrt(x * x + y * y);
    }
};

double getAngle(const Point& a, const Point& b) {
    double dot = a.x * b.x + a.y * b.y;
    double det = a.x * b.y - a.y * b.x;
    return atan2(det, dot);
}

bool check(const vector<Point>& polygon, Point knife) {
    double totalArea = 0;
    for (int i = 0; i < polygon.size(); i++) {
        totalArea += polygon[i].cross(polygon[(i + 1) % polygon.size()]);
    }
    
    Point center;
    for (int i = 0; i < polygon.size(); i++) {
        center.x += (polygon[i].x + polygon[(i + 1) % polygon.size()].x) * polygon[i].cross(polygon[(i + 1) % polygon.size()]);
        center.y += (polygon[i].y + polygon[(i + 1) % polygon.size()].y) * polygon[i].cross(polygon[(i + 1) % polygon.size()]);
    }
    center.x /= (3 * totalArea);
    center.y /= (3 * totalArea);
    
    vector<double> angles;
    for (int i = 0; i < polygon.size(); i++) {
        Point a = polygon[i] - center;
        Point b = polygon[(i + 1) % polygon.size()] - center;
        if ((a.y > EPS) != (b.y > EPS)) {
            angles.push_back(getAngle(a, b));
        }
    }
    
    for (double angle : angles) {
        Point dir(cos(angle), sin(angle));
        double dist = dir.cross(knife - center) / dir.norm();
        if (abs(dist) < EPS) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        polygon[i] = Point(x, y);
    }
    
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        Point knife(x, y);
        
        if (check(polygon, knife)) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    
    return 0;
}