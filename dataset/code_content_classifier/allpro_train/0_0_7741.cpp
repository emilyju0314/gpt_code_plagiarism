#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Segment {
    int x1, y1, x2, y2;
};

struct Circle {
    int x, y, r;
};

int countOwls(int n, int m, vector<Segment>& segments, vector<Circle>& circles) {
    int owlCount = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = 0; k < n; k++) {
                // Check if circles i and j are symmetrical relatively to the straight line containing segment k
                double r = sqrt(pow(circles[i].x - circles[j].x, 2) + pow(circles[i].y - circles[j].y, 2));
                double x0 = (circles[i].x + circles[j].x) / 2.0;
                double y0 = (circles[i].y + circles[j].y) / 2.0;
                double dx = circles[i].x - circles[j].x;
                double dy = circles[i].y - circles[j].y;
                x0 += sqrt(r * r - pow(dx / 2.0, 2));
                y0 += sqrt(r * r - pow(dy / 2.0, 2));
                
                if (abs((segments[k].y2 - segments[k].y1) * (x0 - segments[k].x1) - 
                        (segments[k].y1 - segments[k].y1) * (y0 - segments[k].y1)) > 1e-9) {
                    continue;
                }

                // Check if circles i and j have the same radius and no common points
                if (r != circles[i].r || r != circles[j].r 
                    || pow(circles[i].x - circles[j].x, 2) + pow(circles[i].y - circles[j].y, 2) == pow(2 * r, 2)) {
                    continue;
                }

                // Check if segment k intersects the segment that connects the centers of circles i and j
                double A, B, C;
                A = segments[k].x1 - segments[k].x2;
                B = circles[i].x - circles[j].x;
                C = circles[j].x * segments[k].x2 - circles[j].x * segments[k].x1
                    - circles[i].x * segments[k].x2 + circles[i].x * segments[k].x1;

                double x = (B * C) / (A * B);
                double y = (A * C) / (A * -B);
                
                if (x < min(circles[i].x, circles[j].x) || x > max(circles[i].x, circles[j].x)
                    || y < min(circles[i].y, circles[j].y) || y > max(circles[i].y, circles[j].y)) {
                    continue;
                }

                owlCount++;
            }
        }
    }

    return owlCount;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Segment> segments(n);
    vector<Circle> circles(m);

    for (int i = 0; i < n; i++) {
        cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
    }

    for (int i = 0; i < m; i++) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int result = countOwls(n, m, segments, circles);
    cout << result << endl;

    return 0;
}