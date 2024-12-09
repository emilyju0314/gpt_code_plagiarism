#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool isPossible(vector<Point>& redPoints, vector<Point>& bluePoints, double radius) {
    for (Point& red : redPoints) {
        bool foundBlue = false;
        for (Point& blue : bluePoints) {
            double dist = hypot(red.x - blue.x, red.y - blue.y);
            if (dist < radius) {
                foundBlue = true;
                break;
            }
        }
        if (!foundBlue) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Point> redPoints(n);
    vector<Point> bluePoints(m);

    for (int i = 0; i < n; i++) {
        cin >> redPoints[i].x >> redPoints[i].y;
    }

    for (int i = 0; i < m; i++) {
        cin >> bluePoints[i].x >> bluePoints[i].y;
    }

    double left = 0, right = 1e9;

    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (isPossible(redPoints, bluePoints, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    if (left > 1e8) {
        cout << -1 << endl;
    } else {
        cout << fixed;
        cout.precision(10);
        cout << left << endl;
    }

    return 0;
}