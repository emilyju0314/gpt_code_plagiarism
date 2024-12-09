#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> points;

    for (int i = 0; i < 4; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.push_back({x1, y1});
        points.push_back({x2, y2});
    }

    set<pair<int, int>> distinct_points(points.begin(), points.end());

    if (distinct_points.size() != 4) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (points[i].first == points[j].first || points[i].second == points[j].second) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (points[k].first == points[i].first && points[k].second == points[j].second)
                        cnt++;
                    if (points[k].first == points[j].first && points[k].second == points[i].second)
                        cnt++;
                }

                if (cnt != 2) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}