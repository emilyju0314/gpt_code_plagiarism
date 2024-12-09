#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    Point(int xp, int yp): x(xp), y(yp) {}
};

int dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<Point> pillars;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pillars.push_back(Point(x, y));
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Point p1 = pillars[i], p2 = pillars[j];
                Point p3(p2.x + (p2.y - p1.y), p2.y - (p2.x - p1.x));
                Point p4(p1.x + (p2.y - p1.y), p1.y - (p2.x - p1.x));

                if (find(pillars.begin(), pillars.end(), p3) != pillars.end() && find(pillars.begin(), pillars.end(), p4) != pillars.end()) {
                    int area = dist(p1, p2);
                    max_area = max(max_area, area);
                }
            }
        }

        cout << max_area << endl;
    }

    return 0;
}