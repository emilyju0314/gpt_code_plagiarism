#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    sort(points.begin(), points.end());

    int max_dist = INT_MAX;
    for (int i = 0; i < 2; i++) {
        int max_y = INT_MIN;
        int min_y = INT_MAX;

        for (int j = 0; j < n; j++) {
            max_y = max(max_y, points[j].second);
            min_y = min(min_y, points[j].second);

            int dist = max((points[j].first - points[0].first)*(points[j].first - points[0].first),
                           (max_y - min_y)*(max_y - min_y));

            if (j == n - 1) {
                max_dist = min(max_dist, dist);
            }
        }

        reverse(points.begin(), points.end());
    }

    cout << max_dist << endl;

    return 0;
}