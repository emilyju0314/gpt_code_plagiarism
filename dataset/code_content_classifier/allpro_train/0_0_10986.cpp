#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

double computeArea(const vector<Point>& polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();
        area += (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y);
    }
    return abs(area) / 2.0;
}

int main() {
    int n;
    int caseNum = 1;
    
    while (cin >> n && n != 0) {
        vector<Point> polygon(n);
        for (int i = 0; i < n; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }
        
        double area = computeArea(polygon);
        cout << caseNum << " " << fixed << setprecision(1) << area << endl;
        caseNum++;
    }
    
    return 0;
}