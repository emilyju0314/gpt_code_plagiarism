#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double min_path = 0;
    for (int i = 0; i < N; i++) {
        min_path += dist(points[i], points[(i + 1) % N]);
    }

    cout << min_path << endl;

    return 0;
}