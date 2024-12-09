#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compareY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compareX);
    int max_diff_x = 0;
    for (int i = 0; i < N; i++) {
        int diff = (i == 0) ? points[i].x : (points[i].x - points[i-1].x);
        max_diff_x = max(max_diff_x, diff);
    }
    max_diff_x = max(max_diff_x, W - points[N-1].x);

    sort(points.begin(), points.end(), compareY);
    int max_diff_y = 0;
    for (int i = 0; i < N; i++) {
        int diff = (i == 0) ? points[i].y : (points[i].y - points[i-1].y);
        max_diff_y = max(max_diff_y, diff);
    }
    max_diff_y = max(max_diff_y, H - points[N-1].y);

    cout << 2 * (max_diff_x + max_diff_y) << endl;
    
    return 0;
}