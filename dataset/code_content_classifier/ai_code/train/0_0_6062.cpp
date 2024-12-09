#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<Point, Point>> segments;
    vector<Point> points;

    for (int i = 0; i < n; i++) {
        Point A, B;
        cin >> A.x >> A.y >> B.x >> B.y;
        segments.push_back(make_pair(A, B));

        points.push_back(A);
        points.push_back(B);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = segments[i].first.x;
            int y1 = segments[i].first.y;
            int x2 = segments[i].second.x;
            int y2 = segments[i].second.y;

            int x3 = segments[j].first.x;
            int y3 = segments[j].first.y;
            int x4 = segments[j].second.x;
            int y4 = segments[j].second.y;

            int dx1 = x2 - x1;
            int dy1 = y2 - y1;
            int dx2 = x4 - x3;
            int dy2 = y4 - y3;

            int d1 = gcd(abs(dx1), abs(dy1));
            int d2 = gcd(abs(dx2), abs(dy2));

            dx1 /= d1;
            dy1 /= d1;
            dx2 /= d2;
            dy2 /= d2;

            if (dx1 * dy2 == dx2 * dy1) continue;

            int det = dx1 * dy2 - dx2 * dy1;
            int detx = x3 - x1;
            int dety = y3 - y1;
            
            if (det % 2 == 0 && detx % 2 == 0 && dety % 2 == 0) {
                Point intersect;
                intersect.x = detx / 2 + x1;
                intersect.y = dety / 2 + y1;
                points.push_back(intersect);
            }
        }
    }

    int answer = 0;
    for (Point p : points) {
        bool covered = false;
        for (int i = 0; i < n; i++) {
            int x1 = segments[i].first.x;
            int y1 = segments[i].first.y;
            int x2 = segments[i].second.x;
            int y2 = segments[i].second.y;

            if ((p.x - x1) * (y2 - y1) == (p.y - y1) * (x2 - x1)) {
                covered = true;
                break;
            }
        }
        if (covered) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}