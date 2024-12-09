#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> blue_babies(n);
    vector<pair<int, int>> red_babies(m);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        blue_babies[i] = make_pair(x, y);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        red_babies[i] = make_pair(x, y);
    }

    // Find the required moment of time
    for (int t = 1; t <= 2000; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int blue_x1 = blue_babies[i].first - t;
                int blue_y1 = blue_babies[i].second + t;
                int blue_x2 = blue_babies[i].first + t;
                int blue_y2 = blue_babies[i].second - t;

                int red_x1 = red_babies[j].first + t;
                int red_y1 = red_babies[j].second + t;
                int red_x2 = red_babies[j].first - t;
                int red_y2 = red_babies[j].second - t;

                if ((blue_x1 == red_x1 && blue_y1 == red_y1) || (blue_x2 == red_x2 && blue_y2 == red_y2) ||
                    (blue_x1 == red_x2 && blue_y1 == red_y2) || (blue_x2 == red_x1 && blue_y2 == red_y1)) {
                    cout << t << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Poor Sereja!" << endl;

    return 0;
}