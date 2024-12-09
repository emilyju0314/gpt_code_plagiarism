#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool isInsideTriangle(Point p1, Point p2, Point p3, Point p) {
    int A = (p1.x - p.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p1.y - p.y);
    int B = (p2.x - p.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p.y);
    int C = (p3.x - p.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p3.y - p.y);
    
    return (A >= 0 && B >= 0 && C >= 0) || (A <= 0 && B <= 0 && C <= 0);
}

int countTriangles(int n, vector<Point>& polygon, Point p) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        Point p3 = polygon[(i + 2) % n];
        
        if (isInsideTriangle(p1, p2, p3, p)) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> polygon(n);
    
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        Point p;
        cin >> p.x >> p.y;
        
        cout << countTriangles(n, polygon, p) << endl;
    }
    
    return 0;
}