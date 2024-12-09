#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isInsideTriangle(Point p1, Point p2, Point p3, Point p) {
    int s1 = (p1.x * (p2.y - p.y) + p2.x * (p.y - p1.y) + p.x * (p1.y - p2.y));
    int s2 = (p2.x * (p3.y - p.y) + p3.x * (p.y - p2.y) + p.x * (p2.y - p3.y));
    int s3 = (p3.x * (p1.y - p.y) + p1.x * (p.y - p3.y) + p.x * (p3.y - p1.y));

    return (s1 >= 0 && s2 >= 0 && s3 >= 0) || (s1 <= 0 && s2 <= 0 && s3 <= 0);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (l != i && l != j && l != k) {
                        if (!isInsideTriangle(points[i], points[j], points[k], points[l])) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}