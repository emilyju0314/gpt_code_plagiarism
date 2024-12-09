#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Fence {
    int r, cx, cy;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Point> controlPoints(n);
    for (int i = 0; i < n; i++) {
        cin >> controlPoints[i].x >> controlPoints[i].y;
    }

    vector<Fence> fences(m);
    for (int i = 0; i < m; i++) {
        cin >> fences[i].r >> fences[i].cx >> fences[i].cy;
    }

    for (int i = 0; i < k; i++) {
        int ai, bi;
        cin >> ai >> bi;
        ai--, bi--;

        int minFences = -1;
        for (int j = 0; j < m; j++) {
            int distanceToAi = pow(controlPoints[ai].x - fences[j].cx, 2) + pow(controlPoints[ai].y - fences[j].cy, 2);
            int distanceToBi = pow(controlPoints[bi].x - fences[j].cx, 2) + pow(controlPoints[bi].y - fences[j].cy, 2);

            if (distanceToAi < pow(fences[j].r, 2) && distanceToBi > pow(fences[j].r, 2)) {
                minFences = max(minFences, 0);
            } else if (distanceToAi > pow(fences[j].r, 2) && distanceToBi < pow(fences[j].r, 2)) {
                minFences = max(minFences, 0);
            } else if (distanceToAi > pow(fences[j].r, 2) && distanceToBi > pow(fences[j].r, 2)) {
                minFences = max(minFences, abs(int(sqrt(distanceToAi) / fences[j].r) - int(sqrt(distanceToBi) / fences[j].r)));
            } else {
                minFences = max(minFences, 1);
            }
        }

        cout << minFences << endl;
    }

    return 0;
}