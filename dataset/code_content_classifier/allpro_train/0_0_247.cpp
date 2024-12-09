#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Circle {
    double x, y, r;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double shortestPath(int N, int D, vector<Circle>& circles) {
    if (D == 0) {
        return distance(25, 0, 25, 94);
    }
    
    double ans = DBL_MAX;
    
    for (int i = 0; i < N; i++) {
        double d1 = distance(25, 0, circles[i].x, circles[i].y) - circles[i].r;
        if (d1 < 0) d1 = 0;
        double d2 = distance(25, 94, circles[i].x, circles[i].y) - circles[i].r;
        if (d2 < 0) d2 = 0;
        if (d1 + d2 <= D) {
            ans = min(ans, 2 * sqrt(pow(25 - circles[i].x, 2) + pow(94 - circles[i].y, 2)) - circles[i].r);
        }
    }
    
    if (ans == DBL_MAX) {
        return -1;
    }
    
    return ans;
}

int main() {
    int N, D;
    cin >> N >> D;
    
    vector<Circle> circles(N);
    for (int i = 0; i < N; i++) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    
    double answer = shortestPath(N, D, circles);
    
    cout << fixed << setprecision(10) << answer << endl;
    
    return 0;
}