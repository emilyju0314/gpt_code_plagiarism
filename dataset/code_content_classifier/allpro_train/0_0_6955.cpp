#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Circle {
    int x, y;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n;
    cin >> n;

    vector<Circle> circles(n);
    for (int i = 0; i < n; i++) {
        cin >> circles[i].x >> circles[i].y;
    }

    double minTime = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = distance(circles[i].x, circles[i].y, circles[j].x, circles[j].y);
            if (d < 2) {
                double time = d / 2.0;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        time = min(time, distance(circles[k].x, circles[k].y, circles[i].x, circles[i].y) - 1);
                    }
                }
                minTime = max(minTime, time);
            }
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << minTime << endl;

    return 0;
}