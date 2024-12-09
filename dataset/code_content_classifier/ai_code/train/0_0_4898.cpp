#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calcDistance(Point p1, Point p2, Point p3) {
    double a = p2.y - p1.y;
    double b = p1.x - p2.x;
    double c = p1.y * (p2.x - p1.x) - p1.x * (p2.y - p1.y);
    
    return abs(a * p3.x + b * p3.y + c) / sqrt(a * a + b * b);
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    double maxDist = 1e9;
    
    for (int i = 0; i < n; i++) {
        Point p1 = points[(i - 1 + n) % n];
        Point p2 = points[i];
        Point p3 = points[(i + 1) % n];
        
        maxDist = min(maxDist, calcDistance(p1, p2, p3) / 2);
    }
    
    cout << fixed;
    cout.precision(10);
    cout << maxDist << endl;
    
    return 0;
}