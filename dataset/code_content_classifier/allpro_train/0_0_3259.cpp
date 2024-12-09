#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Point {
    int position;
    char color;
};

bool comparePoints(Point p1, Point p2) {
    return p1.position < p2.position;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].position >> points[i].color;
    }

    sort(points.begin(), points.end(), comparePoints);

    long long dpR = 0, dpB = 0, dpG = 0;
    long long minCost = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (points[i].color == 'R') {
            dpR += points[i].position;
        } else if (points[i].color == 'B') {
            dpB += points[i].position;
        } else {
            dpG += points[i].position;
        }

        minCost = min({minCost, dpR + dpB, dpR + dpG, dpB + dpG});
    }

    cout << minCost << endl;

    return 0;
}