#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int w, h;
        cin >> w >> h;

        int k;
        vector<int> points_x, points_y;

        cin >> k;
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            points_x.push_back(x);
        }

        cin >> k;
        for(int i = 0; i < k; i++) {
            int y;
            cin >> y;
            points_y.push_back(y);
        }

        sort(points_x.begin(), points_x.end());
        sort(points_y.begin(), points_y.end());

        int maxX = points_x.back();
        int maxY = points_y.back();

        // Find the two maximum x and y coordinates
        int a1 = points_x[0], a2 = points_x[1];
        int b1 = points_y[0], b2 = points_y[1];

        // Find the maximum area of triangle
        int maxArea = max(max(a1 * h, (w - a2) * h), max(b1 * w, (h - b2) * w));

        cout << maxArea * 2 << endl;
    }

    return 0;
}