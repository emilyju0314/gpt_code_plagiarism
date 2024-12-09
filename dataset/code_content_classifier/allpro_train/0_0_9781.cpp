#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double solve(vector<Point>& points) {
    int n = points.size();
    double min_length = 1e9;
    int min_turns = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                double length = dist(points[i], points[k]) + dist(points[k], points[j]);
                if (length < min_length) {
                    min_length = length;
                    min_turns = 0;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (l == i || l == j || l == k) continue;
                    double length = dist(points[i], points[j]) + dist(points[j], points[k]) + dist(points[k], points[l]);
                    if (length < min_length) {
                        min_length = length;
                        min_turns = 1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    for (int m = 0; m < n; m++) {
                        if (m == i || m == j || m == k || m == l) continue;
                        double length = dist(points[i], points[j]) + dist(points[j], points[k]) + dist(points[k], points[l]) + dist(points[l], points[m]);
                        if (length < min_length) {
                            min_length = length;
                            min_turns = 2;
                        }
                    }
                }
            }
        }
    }
    
    cout << min_turns << " " << fixed << setprecision(8) << min_length << endl;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        solve(points);
    }
    
    return 0;
}