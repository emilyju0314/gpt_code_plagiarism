#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canReach(vector<pair<int, int>>& intervals, int a, int b) {
    for (int i = 0; i < intervals.size(); i++) {
        if ((intervals[i].first < intervals[a].first && intervals[i].second > intervals[a].first)
            || (intervals[i].first < intervals[a].second && intervals[i].second > intervals[a].second)) {
            if (i == b) return true;
            if (canReach(intervals, i, b)) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            intervals.push_back({x, y});
        } else {
            x--; y--;
            if (canReach(intervals, x, y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}