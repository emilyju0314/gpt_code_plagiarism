#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

double distance(Point p1, Point p2) {
    return hypot(p2.x - p1.x, p2.y - p1.y);
}

double distanceToLine(Point p, Point p1, Point p2) {
    double A = p.x - p1.x;
    double B = p.y - p1.y;
    double C = p2.x - p1.x;
    double D = p2.y - p1.y;
    
    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    
    double param = dot / len_sq;

    double xx, yy;
  
    if (param < 0) {
        xx = p1.x, yy = p1.y;
    } else if (param > 1) {
        xx = p2.x, yy = p2.y;
    } else {
        xx = p1.x + param * C;
        yy = p1.y + param * D;
    }
    
    return distance(p, {xx, yy});
}

int main() {
    int n, H;
    cin >> n >> H;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    double result = 0;
    double current_max_height = 0;
    
    for (int i = 1; i < n; i++) {
        double d = distance(points[i-1], points[i]);
        double height = max(points[i-1].y, points[i].y);
        
        double new_height = max(min(points[i].y, points[i-1].y) + H, current_max_height + H);
        result += distanceToLine({points[i].x, new_height}, points[i-1], points[i]);
        
        current_max_height = height;
    }
    
    cout.precision(10);
    cout << fixed << result << endl;
    
    return 0;
}