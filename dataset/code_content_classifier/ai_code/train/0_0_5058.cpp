#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
    int maxDist = -1;

    for (int x1 = 0; x1 <= n; ++x1) {
        for (int y1 = 0; y1 <= m; ++y1) {
            for (int x2 = 0; x2 <= n; ++x2) {
                for (int y2 = 0; y2 <= m; ++y2) {
                    if (x1 == x2 && y1 == y2) continue;
                    int dist = abs(x1 - x2) + abs(y1 - y2);
                    if (dist > maxDist) {
                        maxDist = dist;
                        p1x = x1; p1y = y1;
                        p2x = x2; p2y = y2;
                    }
                }
            }
        }
    }

    maxDist = -1;

    for (int x3 = 0; x3 <= n; ++x3) {
        for (int y3 = 0; y3 <= m; ++y3) {
            for (int x4 = 0; x4 <= n; ++x4) {
                for (int y4 = 0; y4 <= m; ++y4) {
                    if ((x3 == p1x && y3 == p1y) || (x3 == p2x && y3 == p2y) || 
                        (x4 == p1x && y4 == p1y) || (x4 == p2x && y4 == p2y) ||
                        (x3 == x4 && y3 == y4)) continue;
                    int dist = abs(x3 - x4) + abs(y3 - y4);
                    if (dist > maxDist) {
                        maxDist = dist;
                        p3x = x3; p3y = y3;
                        p4x = x4; p4y = y4;
                    }
                }
            }
        }
    }

    cout << p1x << " " << p1y << endl;
    cout << p2x << " " << p2y << endl;
    cout << p3x << " " << p3y << endl;
    cout << p4x << " " << p4y << endl;

    return 0;
}