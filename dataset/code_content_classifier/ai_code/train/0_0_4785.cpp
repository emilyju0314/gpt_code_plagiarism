#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, idx;
};

double angle(Point a, Point b, Point c) {
    int x1 = a.x - b.x, y1 = a.y - b.y;
    int x2 = c.x - b.x, y2 = c.y - b.y;
    
    double dot_product = x1*x2 + y1*y2;
    double len1 = sqrt(x1*x1 + y1*y1);
    double len2 = sqrt(x2*x2 + y2*y2);
    
    return acos(dot_product / (len1 * len2));
}

bool compare(Point a, Point b) {
    return a.idx < b.idx;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i+1;
    }
    
    vector<int> permutation;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (angle(points[i], points[j], points[k]) < 1.5708) {
                    permutation.push_back(points[i].idx);
                    permutation.push_back(points[j].idx);
                    permutation.push_back(points[k].idx);
                    
                    for (int c = 0; c < n; c++) {
                        if (c == i || c == j || c == k) continue;
                        permutation.push_back(points[c].idx);
                    }
                    
                    for (int num : permutation) {
                        cout << num << " ";
                    }
                    return 0;
                }
            }
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}