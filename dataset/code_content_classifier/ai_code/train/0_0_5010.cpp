#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y, l;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

double maxHeight(const vector<Point>& anchors) {
    double max_h = 0;
    for (double h = 0; h <= 300; h += 0.00001) {
        bool valid = true;
        for (const auto& anchor : anchors) {
            double d = distance(anchor.x, anchor.y, 0, h);
            if (d > anchor.l) {
                valid = false;
                break;
            }
        }
        if (valid) {
            max_h = max(max_h, h);
        }
    }
    return max_h;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<Point> anchors(n);
        for (int i = 0; i < n; ++i) {
            cin >> anchors[i].x >> anchors[i].y >> anchors[i].l;
        }

        double result = maxHeight(anchors);
        cout << fixed;
        cout.precision(7);
        cout << result << endl;
    }

    return 0;
}