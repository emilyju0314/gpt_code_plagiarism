#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    if (n == 1) {
        cout << -1 << endl;
    } else if (n == 2) {
        cout << -1 << endl;
    } else {
        int min_x = 1001, max_x = -1001, min_y = 1001, max_y = -1001;

        for (int i = 0; i < n; i++) {
            min_x = min(min_x, points[i].first);
            max_x = max(max_x, points[i].first);
            min_y = min(min_y, points[i].second);
            max_y = max(max_y, points[i].second);
        }

        int side1 = max_x - min_x;
        int side2 = max_y - min_y;

        if (side1 > 0 && side2 > 0) {
            cout << side1 * side2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}