#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int n, r;
    int case_num = 1;
    
    while (true) {
        cin >> n >> r;
        if (n == 0 && r == 0) {
            break;
        }
        
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        double original_area = 0.0;
        for (int i = 0; i < n; i++) {
            original_area += crossProduct(points[i], points[(i + 1) % n]);
        }
        original_area = abs(original_area) / 2.0;
        
        double max_new_area = 0.0;
        for (int i = 0; i < n; i++) {
            double cur_r = r;
            for (int j = 0; j < n; j++) {
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                double dist = sqrt(dx * dx + dy * dy);
                if (dist <= cur_r) {
                    cur_r -= dist;
                    double new_area = 0.0;
                    for (int k = 0; k < n; k++) {
                        new_area += crossProduct(points[k], points[(k + 1) % n]);
                    }
                    new_area += crossProduct(points[i], points[j]);
                    new_area = abs(new_area) / 2.0;
                    max_new_area = max(max_new_area, new_area);
                } else {
                    double ratio = cur_r / dist;
                    Point intersection;
                    intersection.x = points[i].x + ratio * dx;
                    intersection.y = points[i].y + ratio * dy;
                    
                    double new_area = 0.0;
                    for (int k = 0; k < n; k++) {
                        new_area += crossProduct(points[k], points[(k + 1) % n]);
                    }
                    new_area += crossProduct(points[i], intersection);
                    new_area = abs(new_area) / 2.0;
                    max_new_area = max(max_new_area, new_area);
                    break;
                }
            }
        }
        
        cout << "case " << case_num << ": " << fixed << max_new_area << endl;
        case_num++;
    }
    
    return 0;
}