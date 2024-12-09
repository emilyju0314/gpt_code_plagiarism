#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool checkAlignment(vector<Point>& points, int k) {
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int count = 2;
            for (int m = j + 1; m < points.size(); m++) {
                if ((points[j].y - points[i].y) * (points[m].x - points[i].x) == 
                    (points[m].y - points[i].y) * (points[j].x - points[i].x)) {
                    count++;
                }
            }
            if (count >= k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    if (checkAlignment(points, k)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}