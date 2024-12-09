#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool cmp(Point a, Point b) {
    return a.x < b.x;
}

bool isGoodLine(vector<Point>& points, int i, int j) {
    vector<double> slopes;
    for (int k = 0; k < points.size(); k++) {
        if (k != i && k != j) {
            if (points[k].x == points[i].x && points[k].y == points[i].y) {
                continue; // Same point
            }
            double slope = (double)(points[k].y - points[i].y) / (double)(points[k].x - points[i].x);
            slopes.push_back(slope);
        }
    }

    sort(slopes.begin(), slopes.end());

    for (int k = 0; k < slopes.size() / 2; k++) {
        if (slopes[k] + slopes[slopes.size() - 1 - k] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    if (n < 3) {
        cout << -1 << endl;
        return 0;
    }

    int goodLines = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isGoodLine(points, i, j)) {
                goodLines++;
            }
        }
    }

    cout << goodLines << endl;

    return 0;
}