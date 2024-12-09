#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double area(Point a, Point b, Point c) {
    return abs(crossProduct({b.x - a.x, b.y - a.y}, {c.x - a.x, c.y - a.y})) / 2.0;
}

int main() {
    int N;
    cin >> N;

    vector<Point> hills(N);
    for (int i = 0; i < N; i++) {
        cin >> hills[i].x >> hills[i].y;
    }

    double maxArea = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    maxArea = max(maxArea, area(hills[i], hills[j], hills[k]) + area(hills[i], hills[k], hills[l]));
                }
            }
        }
    }

    cout << fixed << maxArea << endl;

    return 0;
}